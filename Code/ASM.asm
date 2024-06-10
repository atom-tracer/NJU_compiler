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
  li $t0,30
  move $t1,$t0
  li $t2,0
  move $t3,$t2
  li $t4,1
  move $t5,$t4
  li $t6,1
  move $t7,$t6
label0:
  move $s0,$t7
  move $s1,$t1
  ble $s0, $s1, label1
  j label2
label1:
label3:
  move $s2,$t5
  move $s3,$t7
  ble $s2, $s3, label4
  j label5
label4:
  move $s4,$t7
  move $s5,$t7
  move $s6,$t5
  div $s5,$s6
  mflo $s7
  move $t8,$t5
  mul $t9,$s7,$t8
  beq $s4, $t9, label6
  j label7
label6:
  addi $sp, $sp, -4
  sw $t0, 0($sp)
  move $t0,$t3
  addi $sp, $sp, -4
  sw $t1, 0($sp)
  li $t1,1
  addi $sp, $sp, -4
  sw $t2, 0($sp)
  add $t2,$t0,$t1
  move $t3,$t2
label7:
  addi $sp, $sp, -4
  sw $t3, 0($sp)
  move $t3,$t5
  addi $sp, $sp, -4
  sw $t4, 0($sp)
  li $t4,1
  addi $sp, $sp, -4
  sw $t5, 0($sp)
  add $t5,$t3,$t4
  addi $sp, $sp, -4
  sw $t6, 0($sp)
  lw $t6, -60($fp)
  move $t6,$t5
  j label3
label5:
  addi $sp, $sp, -4
  sw $t7, 0($sp)
  lw $t7, -52($fp)
  addi $sp, $sp, -4
  sw $s0, 0($sp)
  move $s0,$t7
  addi $sp, $sp, -4
  sw $s1, 0($sp)
  li $s1,2
  beq $s0, $s1, label8
  j label9
label8:
  addi $sp, $sp, -4
  sw $s2, 0($sp)
  lw $s2, -68($fp)
  addi $sp, $sp, -4
  sw $s3, 0($sp)
  move $s3,$s2
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
  move $a0, $s3
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
label9:
  addi $sp, $sp, -4
  sw $s4, 0($sp)
  li $s4,1
  move $t6,$s4
  addi $sp, $sp, -4
  sw $s5, 0($sp)
  li $s5,0
  move $t7,$s5
  addi $sp, $sp, -4
  sw $s6, 0($sp)
  move $s6,$s2
  addi $sp, $sp, -4
  sw $s7, 0($sp)
  li $s7,1
  addi $sp, $sp, -4
  sw $t8, 0($sp)
  add $t8,$s6,$s7
  move $s2,$t8
  j label0
label2:
  addi $sp, $sp, -4
  sw $t9, 0($sp)
  li $t9,0
  move $v0, $t9
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
