//
// Created by hby on 22-12-2.
//

#ifndef CODE_DATAFLOW_ANALYSIS_H
#define CODE_DATAFLOW_ANALYSIS_H

#include <IR.h>

//// ============================ Dataflow Analysis ============================

typedef struct DataflowAnalysis DataflowAnalysis;

typedef void *Fact;

typedef struct DataflowAnalysis DataflowAnalysis;
struct DataflowAnalysis {
    struct {
        void (*teardown) (DataflowAnalysis *t);
        bool (*isForward) (DataflowAnalysis *t);
        Fact *(*newBoundaryFact) (DataflowAnalysis *t, IR_function *func);// 为函数的入口/出口创建一个边界条件
        Fact *(*newInitialFact) (DataflowAnalysis *t);// 为函数的入口/出口创建一个初始条件
        void (*setInFact) (DataflowAnalysis *t, IR_block *blk, Fact *fact);// 设置块的入口数据流
        void (*setOutFact) (DataflowAnalysis *t, IR_block *blk, Fact *fact);// 设置块的出口数据流
        Fact *(*getInFact) (DataflowAnalysis *t, IR_block *blk);// 获取块的入口数据流
        Fact *(*getOutFact) (DataflowAnalysis *t, IR_block *blk);// 获取块的出口数据流
        bool (*meetInto) (DataflowAnalysis *t, Fact *fact, Fact *target);// 将fact合并到target中
        bool (*transferBlock) (DataflowAnalysis *t, IR_block *block, Fact *in_fact, Fact *out_fact);// 对块进行数据流传递
        void (*printResult) (DataflowAnalysis *t, IR_function *func);
    } const *vTable;
};

//// Fact

// set

DEF_SET(IR_var)
typedef Set_IR_var *Set_ptr_IR_var;
DEF_MAP(IR_block_ptr, Set_ptr_IR_var)

//// ============================ Optimize ============================

extern void remove_dead_block(IR_function *func);
extern void remove_dead_stmt(IR_block *blk);

extern void iterative_solver(DataflowAnalysis *t, IR_function *func);
extern void worklist_solver(DataflowAnalysis *t, IR_function *func);

#endif //CODE_DATAFLOW_ANALYSIS_H
