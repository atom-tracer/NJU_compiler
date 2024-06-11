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

squaRever:
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
  addi $sp, $sp, -288
  lw $t0, -40($fp)
  li $t0,0
  sw $t0, -40($fp)
  lw $t1, -40($fp)
  lw $t2, -44($fp)
  move $t2,$t1
  sw $t2, -44($fp)
  lw $t3, -60($fp)
  li $t3,0
  sw $t3, -60($fp)
  lw $t4, -60($fp)
  lw $t5, -64($fp)
  move $t5,$t4
  sw $t5, -64($fp)
  lw $t6, -68($fp)
  addi $t6,$fp,-56
  sw $t6, -68($fp)
  lw $t7, -72($fp)
  li $t7,0
  sw $t7, -72($fp)
  li $t0,4
  lw $t1, -72($fp)
  lw $t2, -76($fp)
  mul $t2,$t1,$t0
  sw $t2, -76($fp)
  lw $t3, -76($fp)
  lw $t4, -68($fp)
   add $t4,$t4,$t3
  sw $t4, -68($fp)
  lw $t5, -68($fp)
  lw $t6, -80($fp)
  move $t6,$t5
  sw $t6, -80($fp)
  lw $t7, -84($fp)
  move $t7,$a0
  sw $t7, -84($fp)
  lw $t0, -88($fp)
  li $t0,100
  sw $t0, -88($fp)
  lw $t1, -88($fp)
  lw $t2, -84($fp)
  div $t2,$t1
  lw $t3, -92($fp)
   mflo $t3
  sw $t3, -92($fp)
  lw $t5, -92($fp)
  move $t4,$t5
  lw $t6, -80($fp)
  sw $t4,0($t6)
  lw $t7, -96($fp)
  addi $t7,$fp,-56
  sw $t7, -96($fp)
  lw $t0, -100($fp)
  li $t0,1
  sw $t0, -100($fp)
  li $t1,4
  lw $t2, -100($fp)
  lw $t3, -104($fp)
  mul $t3,$t2,$t1
  sw $t3, -104($fp)
  lw $t4, -104($fp)
  lw $t5, -96($fp)
   add $t5,$t5,$t4
  sw $t5, -96($fp)
  lw $t6, -96($fp)
  lw $t7, -108($fp)
  move $t7,$t6
  sw $t7, -108($fp)
  lw $t0, -112($fp)
  move $t0,$a0
  sw $t0, -112($fp)
  lw $t1, -116($fp)
  li $t1,10
  sw $t1, -116($fp)
  lw $t2, -116($fp)
  lw $t3, -112($fp)
  div $t3,$t2
  lw $t4, -120($fp)
   mflo $t4
  sw $t4, -120($fp)
  lw $t5, -124($fp)
  li $t5,10
  sw $t5, -124($fp)
  lw $t6, -128($fp)
  addi $t6,$fp,-56
  sw $t6, -128($fp)
  lw $t7, -132($fp)
  li $t7,0
  sw $t7, -132($fp)
  li $t0,4
  lw $t1, -132($fp)
  lw $t2, -136($fp)
  mul $t2,$t1,$t0
  sw $t2, -136($fp)
  lw $t3, -136($fp)
  lw $t4, -128($fp)
   add $t4,$t4,$t3
  sw $t4, -128($fp)
  lw $t5, -128($fp)
  lw $t6, -140($fp)
  move $t6,$t5
  sw $t6, -140($fp)
  lw $t7, -140($fp)
  lw $t7,0($t7)
  lw $t0, -124($fp)
  lw $t1, -144($fp)
  mul $t1,$t0,$t7
  sw $t1, -144($fp)
  lw $t2, -144($fp)
  lw $t3, -120($fp)
  lw $t4, -148($fp)
   sub $t4,$t3,$t2
  sw $t4, -148($fp)
  lw $t6, -148($fp)
  move $t5,$t6
  lw $t7, -108($fp)
  sw $t5,0($t7)
  lw $t0, -152($fp)
  addi $t0,$fp,-56
  sw $t0, -152($fp)
  lw $t1, -156($fp)
  li $t1,2
  sw $t1, -156($fp)
  li $t2,4
  lw $t3, -156($fp)
  lw $t4, -160($fp)
  mul $t4,$t3,$t2
  sw $t4, -160($fp)
  lw $t5, -160($fp)
  lw $t6, -152($fp)
   add $t6,$t6,$t5
  sw $t6, -152($fp)
  lw $t7, -152($fp)
  lw $t0, -164($fp)
  move $t0,$t7
  sw $t0, -164($fp)
  lw $t1, -168($fp)
  move $t1,$a0
  sw $t1, -168($fp)
  lw $t2, -172($fp)
  li $t2,100
  sw $t2, -172($fp)
  lw $t3, -176($fp)
  addi $t3,$fp,-56
  sw $t3, -176($fp)
  lw $t4, -180($fp)
  li $t4,0
  sw $t4, -180($fp)
  li $t5,4
  lw $t6, -180($fp)
  lw $t7, -184($fp)
  mul $t7,$t6,$t5
  sw $t7, -184($fp)
  lw $t0, -184($fp)
  lw $t1, -176($fp)
   add $t1,$t1,$t0
  sw $t1, -176($fp)
  lw $t2, -176($fp)
  lw $t3, -188($fp)
  move $t3,$t2
  sw $t3, -188($fp)
  lw $t4, -188($fp)
  lw $t4,0($t4)
  lw $t5, -172($fp)
  lw $t6, -192($fp)
  mul $t6,$t5,$t4
  sw $t6, -192($fp)
  lw $t7, -192($fp)
  lw $t0, -168($fp)
  lw $t1, -196($fp)
   sub $t1,$t0,$t7
  sw $t1, -196($fp)
  lw $t2, -200($fp)
  li $t2,10
  sw $t2, -200($fp)
  lw $t3, -204($fp)
  addi $t3,$fp,-56
  sw $t3, -204($fp)
  lw $t4, -208($fp)
  li $t4,1
  sw $t4, -208($fp)
  li $t5,4
  lw $t6, -208($fp)
  lw $t7, -212($fp)
  mul $t7,$t6,$t5
  sw $t7, -212($fp)
  lw $t0, -212($fp)
  lw $t1, -204($fp)
   add $t1,$t1,$t0
  sw $t1, -204($fp)
  lw $t2, -204($fp)
  lw $t3, -216($fp)
  move $t3,$t2
  sw $t3, -216($fp)
  lw $t4, -216($fp)
  lw $t4,0($t4)
  lw $t5, -200($fp)
  lw $t6, -220($fp)