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
  mul $t6,$t5,$t4
  sw $t6, -220($fp)
  lw $t7, -220($fp)
  lw $t0, -196($fp)
  lw $t1, -224($fp)
   sub $t1,$t0,$t7
  sw $t1, -224($fp)
  lw $t3, -224($fp)
  move $t2,$t3
  lw $t4, -164($fp)
  sw $t2,0($t4)
  lw $t5, -228($fp)
  addi $t5,$fp,-56
  sw $t5, -228($fp)
  lw $t6, -232($fp)
  li $t6,0
  sw $t6, -232($fp)
  li $t7,4
  lw $t0, -232($fp)
  lw $t1, -236($fp)
  mul $t1,$t0,$t7
  sw $t1, -236($fp)
  lw $t2, -236($fp)
  lw $t3, -228($fp)
   add $t3,$t3,$t2
  sw $t3, -228($fp)
  lw $t4, -228($fp)
  lw $t5, -240($fp)
  move $t5,$t4
  sw $t5, -240($fp)
  lw $t6, -244($fp)
  addi $t6,$fp,-56
  sw $t6, -244($fp)
  lw $t7, -248($fp)
  li $t7,2
  sw $t7, -248($fp)
  li $t0,4
  lw $t1, -248($fp)
  lw $t2, -252($fp)
  mul $t2,$t1,$t0
  sw $t2, -252($fp)
  lw $t3, -252($fp)
  lw $t4, -244($fp)
   add $t4,$t4,$t3
  sw $t4, -244($fp)
  lw $t5, -244($fp)
  lw $t6, -256($fp)
  move $t6,$t5
  sw $t6, -256($fp)
  lw $t7, -256($fp) //t44
  lw $t7,0($t7)
  lw $t0, -240($fp) //t43
  lw $t0,0($t0)
  bne $t0, $t7, label0
  j label1
label0:
  lw $t1, -260($fp)
  li $t1,0
  sw $t1, -260($fp)
  lw $t2, -260($fp)
  lw $t3, -44($fp)
  move $t3,$t2
  sw $t3, -44($fp)
  j label2
label1:
label3:
  lw $t4, -64($fp)
  lw $t5, -264($fp)
  move $t5,$t4
  sw $t5, -264($fp)
  lw $t6, -268($fp)
  li $t6,12
  sw $t6, -268($fp)
  lw $t7, -268($fp)
  lw $t0, -264($fp)
  blt $t0, $t7, label4
  j label5
label4:
  lw $t1, -64($fp)
  lw $t2, -272($fp)
  move $t2,$t1
  sw $t2, -272($fp)
  lw $t3, -64($fp)
  lw $t4, -276($fp)
  move $t4,$t3
  sw $t4, -276($fp)
  lw $t5, -276($fp)
  lw $t6, -272($fp)
  lw $t7, -280($fp)
  mul $t7,$t6,$t5
  sw $t7, -280($fp)
  lw $t0, -284($fp)
  move $t0,$a0
  sw $t0, -284($fp)
  lw $t1, -284($fp)
  lw $t2, -280($fp)
  lw $t3, -288($fp)
   sub $t3,$t2,$t1
  sw $t3, -288($fp)
  lw $t4, -292($fp)
  li $t4,0
  sw $t4, -292($fp)
  lw $t5, -292($fp)
  lw $t6, -288($fp)
  beq $t6, $t5, label6
  j label7
label6:
  lw $t7, -296($fp)
  li $t7,1
  sw $t7, -296($fp)
  lw $t0, -296($fp)
  lw $t1, -44($fp)
  move $t1,$t0
  sw $t1, -44($fp)
label7:
  lw $t2, -64($fp)
  lw $t3, -300($fp)
  move $t3,$t2
  sw $t3, -300($fp)
  lw $t4, -304($fp)
  li $t4,1
  sw $t4, -304($fp)
  lw $t5, -304($fp)
  lw $t6, -300($fp)
  lw $t7, -308($fp)
   add $t7,$t6,$t5
  sw $t7, -308($fp)
  lw $t0, -308($fp)
  lw $t1, -64($fp)
  move $t1,$t0
  sw $t1, -64($fp)
  j label3
label5:
label2:
  lw $t2, -44($fp)
  lw $t3, -312($fp)
  move $t3,$t2
  sw $t3, -312($fp)
  lw $t4, -316($fp)
  li $t4,1
  sw $t4, -316($fp)
  lw $t5, -316($fp)
  lw $t6, -312($fp)
  beq $t6, $t5, label8
  j label9
label8:
  lw $t7, -320($fp)
  li $t7,1
  sw $t7, -320($fp)
  lw $t0, -320($fp)
  move $v0, $t0
  sw $t0, -320($fp)
  addi $sp, $sp, 280
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
  j label10
label9:
  lw $t1, -324($fp)
  li $t1,0
  sw $t1, -324($fp)
  lw $t2, -324($fp)
  move $v0, $t2
  sw $t2, -324($fp)
  addi $sp, $sp, 280
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
label10:

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
  addi $sp, $sp, -48
  lw $t3, -40($fp)
  li $t3,100
  sw $t3, -40($fp)
  lw $t4, -40($fp)
  lw $t5, -44($fp)
  move $t5,$t4
  sw $t5, -44($fp)
label11:
  lw $t6, -44($fp)
  lw $t7, -48($fp)
  move $t7,$t6
  sw $t7, -48($fp)
  lw $t0, -52($fp)
  li $t0,150
  sw $t0, -52($fp)
  lw $t1, -52($fp)
  lw $t2, -48($fp)
  blt $t2, $t1, label12
  j label13
label12:
  lw $t3, -44($fp)
  lw $t4, -56($fp)
  move $t4,$t3
  sw $t4, -56($fp)
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
  lw $a0, -56($fp)
  jal squaRever
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
  lw $t5, -60($fp)
  move $t5,$v0
  sw $t5, -60($fp)
  lw $t6, -64($fp)
  li $t6,1
  sw $t6, -64($fp)
  lw $t7, -64($fp)
  lw $t0, -60($fp)
  beq $t0, $t7, label14
  j label15
label14:
  lw $t1, -44($fp)
  lw $t2, -68($fp)
  move $t2,$t1
  sw $t2, -68($fp)
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
  lw $a0, -68($fp)
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
label15:
  lw $t3, -44($fp)
  lw $t4, -72($fp)
  move $t4,$t3
  sw $t4, -72($fp)
  lw $t5, -76($fp)
  li $t5,1
  sw $t5, -76($fp)
  lw $t6, -76($fp)
  lw $t7, -72($fp)
  lw $t0, -80($fp)
   add $t0,$t7,$t6
  sw $t0, -80($fp)
  lw $t1, -80($fp)
  lw $t2, -44($fp)
  move $t2,$t1
  sw $t2, -44($fp)
  j label11
label13:
  lw $t3, -84($fp)
  li $t3,0
  sw $t3, -84($fp)
  lw $t4, -84($fp)
  move $v0, $t4
  sw $t4, -84($fp)
  addi $sp, $sp, 48
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
