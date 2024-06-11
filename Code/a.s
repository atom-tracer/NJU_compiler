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

hanoi:
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
  addi $sp, $sp, -108
  lw $t0, -40($fp)
  move $t0,$a0
  sw $t0, -40($fp)
  lw $t1, -44($fp)
  li $t1,1
  sw $t1, -44($fp)
  lw $t2, -44($fp)
  lw $t3, -40($fp)
  beq $t3, $t2, label0
  sw $t2, -44($fp)
  sw $t3, -40($fp)
  j label1
label0:
  lw $t4, -48($fp)
  move $t4,$a1
  sw $t4, -48($fp)
  lw $t5, -52($fp)
  li $t5,1000000
  sw $t5, -52($fp)
  lw $t6, -52($fp)
  lw $t7, -48($fp)
  lw $t0, -56($fp)
  mul $t0,$t7,$t6
  sw $t0, -56($fp)
  sw $t6, -52($fp)
  sw $t7, -48($fp)
  lw $t1, -60($fp)
  move $t1,$a3
  sw $t1, -60($fp)
  lw $t2, -60($fp)
  lw $t3, -56($fp)
  lw $t4, -64($fp)
   add $t4,$t3,$t2
  sw $t4, -64($fp)
  sw $t2, -60($fp)
  sw $t3, -56($fp)
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
  lw $a0, -64($fp)
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
  lw $t5, -68($fp)
  move $t5,$a0
  sw $t5, -68($fp)
  lw $t6, -72($fp)
  li $t6,1
  sw $t6, -72($fp)
  lw $t7, -72($fp)
  lw $t0, -68($fp)
  lw $t1, -76($fp)
   sub $t1,$t0,$t7
  sw $t1, -76($fp)
  sw $t0, -68($fp)
  sw $t7, -72($fp)
  lw $t2, -80($fp)
  move $t2,$a1
  sw $t2, -80($fp)
  lw $t3, -84($fp)
  move $t3,$a3
  sw $t3, -84($fp)
  lw $t4, -88($fp)
  move $t4,$a2
  sw $t4, -88($fp)
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
  lw $a0, -76($fp)
  lw $a1, -80($fp)
  lw $a2, -84($fp)
  lw $a3, -88($fp)
  jal hanoi
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
  lw $t5, -92($fp)
  move $t5,$v0
  sw $t5, -92($fp)
  lw $t6, -96($fp)
  move $t6,$a1
  sw $t6, -96($fp)
  lw $t7, -100($fp)
  li $t7,1000000
  sw $t7, -100($fp)
  lw $t0, -100($fp)
  lw $t1, -96($fp)
  lw $t2, -104($fp)
  mul $t2,$t1,$t0
  sw $t2, -104($fp)
  sw $t0, -100($fp)
  sw $t1, -96($fp)
  lw $t3, -108($fp)
  move $t3,$a3
  sw $t3, -108($fp)
  lw $t4, -108($fp)
  lw $t5, -104($fp)
  lw $t6, -112($fp)
   add $t6,$t5,$t4
  sw $t6, -112($fp)
  sw $t4, -108($fp)
  sw $t5, -104($fp)
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
  lw $t7, -116($fp)
  move $t7,$a0
  sw $t7, -116($fp)
  lw $t0, -120($fp)
  li $t0,1
  sw $t0, -120($fp)
  lw $t1, -120($fp)
  lw $t2, -116($fp)
  lw $t3, -124($fp)
   sub $t3,$t2,$t1
  sw $t3, -124($fp)
  sw $t1, -120($fp)
  sw $t2, -116($fp)
  lw $t4, -128($fp)
  move $t4,$a2
  sw $t4, -128($fp)
  lw $t5, -132($fp)
  move $t5,$a1
  sw $t5, -132($fp)
  lw $t6, -136($fp)
  move $t6,$a3
  sw $t6, -136($fp)
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
  lw $a0, -124($fp)
  lw $a1, -128($fp)
  lw $a2, -132($fp)
  lw $a3, -136($fp)
  jal hanoi
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
  lw $t7, -140($fp)
  move $t7,$v0
  sw $t7, -140($fp)
label2:
  lw $t0, -144($fp)
  li $t0,0
  sw $t0, -144($fp)
  lw $t1, -144($fp)
  move $v0, $t1
  sw $t1, -144($fp)
  addi $sp, $sp, 108
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
  addi $sp, $sp, -32
  lw $t2, -40($fp)
  li $t2,3
  sw $t2, -40($fp)
  lw $t3, -40($fp)
  lw $t4, -44($fp)
  move $t4,$t3
  sw $t4, -44($fp)
  sw $t3, -40($fp)
  lw $t5, -44($fp)
  lw $t6, -48($fp)
  move $t6,$t5
  sw $t6, -48($fp)
  sw $t5, -44($fp)
  lw $t7, -52($fp)
  li $t7,1
  sw $t7, -52($fp)
  lw $t0, -56($fp)
  li $t0,2
  sw $t0, -56($fp)
  lw $t1, -60($fp)
  li $t1,3
  sw $t1, -60($fp)
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
  lw $a0, -48($fp)
  lw $a1, -52($fp)
  lw $a2, -56($fp)
  lw $a3, -60($fp)
  jal hanoi
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
  lw $t2, -64($fp)
  move $t2,$v0
  sw $t2, -64($fp)
  lw $t3, -68($fp)
  li $t3,0
  sw $t3, -68($fp)
  lw $t4, -68($fp)
  move $v0, $t4
  sw $t4, -68($fp)
  addi $sp, $sp, 32
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
