.data
_prompt: .asciiz "Enter an integer:"
_ret: .asciiz "\n"
.globl main
.text
read:
  li $v0, 4
  la $a0, _prompt
  syscall
  li $v0, 5
  syscall
  jr $ra

write:
  li $v0, 1
  syscall
  li $v0, 4
  la $a0, _ret
  syscall
  move $v0, $0
  jr $ra

main:
  addi $sp, $sp, -36
  sw $fp, 32($sp)
  addi $fp, $sp, 36
  sw $s0, 0($sp)
  sw $s1, 4($sp)
  sw $s2, 8($sp)
  sw $s3, 12($sp)
  sw $s4, 16($sp)
  sw $s5, 20($sp)
  sw $s6, 24($sp)
  sw $s7, 28($sp)
  addi $sp, $sp, -4
  addi $sp, $sp, -4
  addi $sp, $sp, -4
  addi $sp, $sp, -4
  addi $sp, $sp, -4
  addi $sp, $sp, -4
  addi $sp, $sp, -4
  addi $sp, $sp, -4
  addi $sp, $sp, -4
  addi $sp, $sp, -4
  addi $sp, $sp, -4
  addi $sp, $sp, -4
  addi $sp, $sp, -4
  addi $sp, $sp, -4
  addi $sp, $sp, -4
  addi $sp, $sp, -4
  addi $sp, $sp, -4
  addi $sp, $sp, -4
  addi $sp, $sp, -4
  addi $sp, $sp, -4
  addi $sp,$sp,-60
  sw $t0,16($sp)
  sw $t1,20($sp)
  sw $t2,24($sp)
  sw $t3,28($sp)
  sw $t4,32($sp)
  sw $t5,36($sp)
  sw $t6,40($sp)
  sw $t7,44($sp)
  sw $t8,48($sp)
  sw $t9,52($sp)
  sw $a0,0($sp)
  sw $a1,4($sp)
  sw $a2,8($sp)
  sw $a3,12($sp)
  sw $ra,56($sp)
  jal read
  lw $t0,16($sp)
  lw $t1,20($sp)
  lw $t2,24($sp)
  lw $t3,28($sp)
  lw $t4,32($sp)
  lw $t5,36($sp)
  lw $t6,40($sp)
  lw $t7,44($sp)
  lw $t8,48($sp)
  lw $t9,52($sp)
  lw $a0,0($sp)
  lw $a1,4($sp)
  lw $a2,8($sp)
  lw $a3,12($sp)
  lw $ra,56($sp)
  addi $sp,$sp,60
  lw $t0, -40($fp)
  lw $t1, -44($fp)
  move $t1,$t0
  sw $t1, -44($fp)
  sw $t0, -40($fp)
  lw $t2, -44($fp)
  lw $t3, -48($fp)
  move $t3,$t2
  sw $t3, -48($fp)
  sw $t2, -44($fp)
  lw $t4, -52($fp)
  li $t4,0
  sw $t4, -52($fp)
  lw $t5, -52($fp)
  lw $t6, -48($fp)
  bgt $t6, $t5, label0
  sw $t6, -48($fp)
  sw $t5, -52($fp)
  j label1
label0:
  lw $t7, -72($fp)
  li $t7,1
  sw $t7, -72($fp)
  addi $sp,$sp,-60
  sw $t0,16($sp)
  sw $t1,20($sp)
  sw $t2,24($sp)
  sw $t3,28($sp)
  sw $t4,32($sp)
  sw $t5,36($sp)
  sw $t6,40($sp)
  sw $t7,44($sp)
  sw $t8,48($sp)
  sw $t9,52($sp)
  sw $a0,0($sp)
  sw $a1,4($sp)
  sw $a2,8($sp)
  sw $a3,12($sp)
  sw $ra,56($sp)
  lw $a0, -72($fp)
  jal write
  lw $t0,16($sp)
  lw $t1,20($sp)
  lw $t2,24($sp)
  lw $t3,28($sp)
  lw $t4,32($sp)
  lw $t5,36($sp)
  lw $t6,40($sp)
  lw $t7,44($sp)
  lw $t8,48($sp)
  lw $t9,52($sp)
  lw $a0,0($sp)
  lw $a1,4($sp)
  lw $a2,8($sp)
  lw $a3,12($sp)
  lw $ra,56($sp)
  addi $sp,$sp,60
  j label2
label1:
  lw $t0, -44($fp)
  lw $t1, -80($fp)
  move $t1,$t0
  sw $t1, -80($fp)
  sw $t0, -44($fp)
  lw $t2, -84($fp)
  li $t2,0
  sw $t2, -84($fp)
  lw $t3, -84($fp)
  lw $t4, -80($fp)
  blt $t4, $t3, label3
  sw $t4, -80($fp)
  sw $t3, -84($fp)
  j label4
label3:
  lw $t5, -100($fp)
  li $t5,1
  sw $t5, -100($fp)
  lw $t6, -104($fp)
  li $t6,0
  lw $t7, -100($fp)
  sub $t6,$t6,$t7
  sw $t7, -100($fp)
  sw $t6, -104($fp)
  addi $sp,$sp,-60
  sw $t0,16($sp)
  sw $t1,20($sp)
  sw $t2,24($sp)
  sw $t3,28($sp)
  sw $t4,32($sp)
  sw $t5,36($sp)
  sw $t6,40($sp)
  sw $t7,44($sp)
  sw $t8,48($sp)
  sw $t9,52($sp)
  sw $a0,0($sp)
  sw $a1,4($sp)
  sw $a2,8($sp)
  sw $a3,12($sp)
  sw $ra,56($sp)
  lw $a0, -104($fp)
  jal write
  lw $t0,16($sp)
  lw $t1,20($sp)
  lw $t2,24($sp)
  lw $t3,28($sp)
  lw $t4,32($sp)
  lw $t5,36($sp)
  lw $t6,40($sp)
  lw $t7,44($sp)
  lw $t8,48($sp)
  lw $t9,52($sp)
  lw $a0,0($sp)
  lw $a1,4($sp)
  lw $a2,8($sp)
  lw $a3,12($sp)
  lw $ra,56($sp)
  addi $sp,$sp,60
  j label5
label4:
  lw $t0, -112($fp)
  li $t0,0
  sw $t0, -112($fp)
  addi $sp,$sp,-60
  sw $t0,16($sp)
  sw $t1,20($sp)
  sw $t2,24($sp)
  sw $t3,28($sp)
  sw $t4,32($sp)
  sw $t5,36($sp)
  sw $t6,40($sp)
  sw $t7,44($sp)
  sw $t8,48($sp)
  sw $t9,52($sp)
  sw $a0,0($sp)
  sw $a1,4($sp)
  sw $a2,8($sp)
  sw $a3,12($sp)
  sw $ra,56($sp)
  lw $a0, -112($fp)
  jal write
  lw $t0,16($sp)
  lw $t1,20($sp)
  lw $t2,24($sp)
  lw $t3,28($sp)
  lw $t4,32($sp)
  lw $t5,36($sp)
  lw $t6,40($sp)
  lw $t7,44($sp)
  lw $t8,48($sp)
  lw $t9,52($sp)
  lw $a0,0($sp)
  lw $a1,4($sp)
  lw $a2,8($sp)
  lw $a3,12($sp)
  lw $ra,56($sp)
  addi $sp,$sp,60
label5:
label2:
  lw $t1, -116($fp)
  li $t1,0
  sw $t1, -116($fp)
  lw $t2, -116($fp)
  move $v0, $t2
  sw $t2, -116($fp)
  addi $sp, $fp, -36
  lw $s0, 0($sp)
  lw $s1, 4($sp)
  lw $s2, 8($sp)
  lw $s3, 12($sp)
  lw $s4, 16($sp)
  lw $s5, 20($sp)
  lw $s6, 24($sp)
  lw $s7, 28($sp)
  lw $fp, 32($sp)
  addi $sp, $sp, 36
  jr $ra
