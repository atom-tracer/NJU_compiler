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
  addi $sp, $sp, -52
  lw $t0, -40($fp)
  li $t0,1
  sw $t0, -40($fp)
  lw $t1, -40($fp)
  lw $t2, -44($fp)
  move $t2,$t1
  sw $t2, -44($fp)
  sw $t1, -40($fp)
  lw $t3, -48($fp)
  li $t3,1
  sw $t3, -48($fp)
  lw $t4, -48($fp)
  lw $t5, -52($fp)
  move $t5,$t4
  sw $t5, -52($fp)
  sw $t4, -48($fp)
label0:
  lw $t6, -52($fp)
  lw $t7, -56($fp)
  move $t7,$t6
  sw $t7, -56($fp)
  sw $t6, -52($fp)
  lw $t0, -60($fp)
  move $t0,$a0
  sw $t0, -60($fp)
  lw $t1, -60($fp)
  lw $t2, -56($fp)
  ble $t2, $t1, label1
  sw $t1, -60($fp)
  sw $t2, -56($fp)
  j label2
label1:
  lw $t3, -44($fp)
  lw $t4, -64($fp)
  move $t4,$t3
  sw $t4, -64($fp)
  sw $t3, -44($fp)
  lw $t5, -52($fp)
  lw $t6, -68($fp)
  move $t6,$t5
  sw $t6, -68($fp)
  sw $t5, -52($fp)
  lw $t7, -68($fp)
  lw $t0, -64($fp)
  lw $t1, -72($fp)
   mul $t1,$t0,$t7
  sw $t1, -72($fp)
  sw $t0, -64($fp)
  sw $t7, -68($fp)
  lw $t2, -72($fp)
  lw $t3, -44($fp)
  move $t3,$t2
  sw $t3, -44($fp)
  sw $t2, -72($fp)
  lw $t4, -52($fp)
  lw $t5, -76($fp)
  move $t5,$t4
  sw $t5, -76($fp)
  sw $t4, -52($fp)
  lw $t6, -80($fp)
  li $t6,1
  sw $t6, -80($fp)
  lw $t7, -80($fp)
  lw $t0, -76($fp)
  lw $t1, -84($fp)
   add $t1,$t0,$t7
  sw $t1, -84($fp)
  sw $t0, -76($fp)
  sw $t7, -80($fp)
  lw $t2, -84($fp)
  lw $t3, -52($fp)
  move $t3,$t2
  sw $t3, -52($fp)
  sw $t2, -84($fp)
  j label0
label2:
  lw $t4, -44($fp)
  lw $t5, -88($fp)
  move $t5,$t4
  sw $t5, -88($fp)
  sw $t4, -44($fp)
  lw $t6, -88($fp)
  move $v0, $t6
  sw $t6, -88($fp)
  addi $sp, $sp, 52
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
  addi $sp, $sp, -92
  lw $t7, -60($fp)
  li $t7,0
  sw $t7, -60($fp)
  lw $t0, -60($fp)
  lw $t1, -64($fp)
  move $t1,$t0
  sw $t1, -64($fp)
  sw $t0, -60($fp)
  lw $t2, -68($fp)
  li $t2,5
  sw $t2, -68($fp)
  lw $t3, -68($fp)
  lw $t4, -72($fp)
  move $t4,$t3
  sw $t4, -72($fp)
  sw $t3, -68($fp)
label3:
  lw $t5, -64($fp)
  lw $t6, -76($fp)
  move $t6,$t5
  sw $t6, -76($fp)
  sw $t5, -64($fp)
  lw $t7, -72($fp)
  lw $t0, -80($fp)
  move $t0,$t7
  sw $t0, -80($fp)
  sw $t7, -72($fp)
  lw $t1, -80($fp)
  lw $t2, -76($fp)
  blt $t2, $t1, label4
  sw $t1, -80($fp)
  sw $t2, -76($fp)
  j label5
label4:
  lw $t3, -84($fp)
  addi $t3,$fp,-56
  sw $t3, -84($fp)
  lw $t4, -64($fp)
  lw $t5, -88($fp)
  move $t5,$t4
  sw $t5, -88($fp)
  sw $t4, -64($fp)
  li $t6,4
  lw $t7, -88($fp)
  lw $t0, -92($fp)
   mul $t0,$t7,$t6
  sw $t0, -92($fp)
  sw $t7, -88($fp)
  lw $t1, -92($fp)
  lw $t2, -84($fp)
   add $t2,$t2,$t1
  sw $t2, -84($fp)
  sw $t1, -92($fp)
  lw $t3, -84($fp)
  lw $t4, -96($fp)
  move $t4,$t3
  sw $t4, -96($fp)
  sw $t3, -84($fp)
  lw $t5, -64($fp)
  lw $t6, -100($fp)
  move $t6,$t5
  sw $t6, -100($fp)
  sw $t5, -64($fp)
  lw $t7, -104($fp)
  li $t7,2
  sw $t7, -104($fp)
  lw $t0, -104($fp)
  lw $t1, -100($fp)
  lw $t2, -108($fp)
   add $t2,$t1,$t0
  sw $t2, -108($fp)
  sw $t0, -104($fp)
  sw $t1, -100($fp)
  lw $t4, -108($fp)
  move $t3,$t4
  lw $t5, -96($fp)
  sw $t3,0($t5)
  sw $t4, -108($fp)
  sw $t5, -96($fp)
  lw $t6, -112($fp)
  addi $t6,$fp,-56
  sw $t6, -112($fp)
  lw $t7, -64($fp)
  lw $t0, -116($fp)
  move $t0,$t7
  sw $t0, -116($fp)
  sw $t7, -64($fp)
  li $t1,4
  lw $t2, -116($fp)
  lw $t3, -120($fp)
   mul $t3,$t2,$t1
  sw $t3, -120($fp)
  sw $t2, -116($fp)
  lw $t4, -120($fp)
  lw $t5, -112($fp)
   add $t5,$t5,$t4
  sw $t5, -112($fp)
  sw $t4, -120($fp)
  lw $t6, -112($fp)
  lw $t7, -124($fp)
  move $t7,$t6
  sw $t7, -124($fp)
  sw $t6, -112($fp)
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
  lw $a0,0($a0)
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
  lw $t0, -128($fp)
  move $t0,$v0
  sw $t0, -128($fp)
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
  lw $a0, -128($fp)
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
  lw $t1, -64($fp)
  lw $t2, -132($fp)
  move $t2,$t1
  sw $t2, -132($fp)
  sw $t1, -64($fp)
  lw $t3, -136($fp)
  li $t3,1
  sw $t3, -136($fp)
  lw $t4, -136($fp)
  lw $t5, -132($fp)
  lw $t6, -140($fp)
   add $t6,$t5,$t4
  sw $t6, -140($fp)
  sw $t4, -136($fp)
  sw $t5, -132($fp)
  lw $t7, -140($fp)
  lw $t0, -64($fp)
  move $t0,$t7
  sw $t0, -64($fp)
  sw $t7, -140($fp)
  j label3
label5:
  lw $t1, -144($fp)
  li $t1,0
  sw $t1, -144($fp)
  lw $t2, -144($fp)
  move $v0, $t2
  sw $t2, -144($fp)
  addi $sp, $sp, 92
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
