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

fact:
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
  addi $sp, $sp, -64
  lw $t0, -44($fp)
  move $t0,$a0
  sw $t0, -44($fp)
  lw $t1, -48($fp)
  li $t1,1
  sw $t1, -48($fp)
  lw $t2, -48($fp)
  lw $t3, -44($fp)
  beq $t3, $t2, label0
  sw $t3, -44($fp)
  sw $t2, -48($fp)
  j label1
label0:
  lw $t4, -68($fp)
  move $t4,$a0
  sw $t4, -68($fp)
  lw $t5, -68($fp)
  move $v0, $t5
  sw $t5, -68($fp)
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
  j label2
label1:
  lw $t6, -76($fp)
  move $t6,$a0
  sw $t6, -76($fp)
  lw $t7, -80($fp)
  move $t7,$a0
  sw $t7, -80($fp)
  lw $t0, -84($fp)
  li $t0,1
  sw $t0, -84($fp)
  lw $t1, -84($fp)
  lw $t2, -80($fp)
  lw $t3, -88($fp)
  sub $t3,$t2,$t1
  sw $t2, -80($fp)
  sw $t1, -84($fp)
  sw $t3, -88($fp)
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
  lw $a0, -88($fp)
  jal fact
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
  lw $t4, -92($fp)
  move $t4,$v0
  sw $t4, -92($fp)
  lw $t5, -92($fp)
  lw $t6, -76($fp)
  lw $t7, -100($fp)
  mul $t7,$t6,$t5
  sw $t6, -76($fp)
  sw $t5, -92($fp)
  sw $t7, -100($fp)
  lw $t0, -100($fp)
  move $v0, $t0
  sw $t0, -100($fp)
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
label2:

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
  addi $sp, $sp, -64
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
  lw $t1, -68($fp)
  move $t1,$v0
  sw $t1, -68($fp)
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
  lw $t2, -68($fp)
  lw $t3, -72($fp)
  move $t3,$t2
  sw $t3, -72($fp)
  sw $t2, -68($fp)
  lw $t4, -72($fp)
  lw $t5, -76($fp)
  move $t5,$t4
  sw $t5, -76($fp)
  sw $t4, -72($fp)
  lw $t6, -80($fp)
  li $t6,1
  sw $t6, -80($fp)
  lw $t7, -80($fp)
  lw $t0, -76($fp)
  bgt $t0, $t7, label3
  sw $t0, -76($fp)
  sw $t7, -80($fp)
  j label4
label3:
  lw $t1, -72($fp)
  lw $t2, -100($fp)
  move $t2,$t1
  sw $t2, -100($fp)
  sw $t1, -72($fp)
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
  lw $a0, -100($fp)
  jal fact
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
  lw $t3, -104($fp)
  move $t3,$v0
  sw $t3, -104($fp)
  lw $t4, -104($fp)
  lw $t5, -112($fp)
  move $t5,$t4
  sw $t5, -112($fp)
  sw $t4, -104($fp)
  j label5
label4:
  lw $t6, -120($fp)
  li $t6,1
  sw $t6, -120($fp)
  lw $t7, -120($fp)
  lw $t0, -112($fp)
  move $t0,$t7
  sw $t0, -112($fp)
  sw $t7, -120($fp)
label5:
  lw $t1, -112($fp)
  lw $t2, -124($fp)
  move $t2,$t1
  sw $t2, -124($fp)
  sw $t1, -112($fp)
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
  lw $t3, -128($fp)
  li $t3,0
  sw $t3, -128($fp)
  lw $t4, -128($fp)
  move $v0, $t4
  sw $t4, -128($fp)
  addi $sp, $fp, -64
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
