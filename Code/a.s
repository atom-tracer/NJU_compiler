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
  addi $sp, $sp, -416
  lw $t0, -92($fp)
  li $t0,0
  sw $t0, -92($fp)
  lw $t1, -92($fp)
  lw $t2, -96($fp)
  move $t2,$t1
  sw $t2, -96($fp)
label0:
  lw $t3, -96($fp)
  lw $t4, -120($fp)
  move $t4,$t3
  sw $t4, -120($fp)
  lw $t5, -124($fp)
  li $t5,5
  sw $t5, -124($fp)
  lw $t6, -124($fp)
  lw $t7, -120($fp)
  blt $t7, $t6, label1
  j label2
label1:
  lw $t0, -128($fp)
  addi $t0,$fp,-116
  sw $t0, -128($fp)
  lw $t1, -96($fp)
  lw $t2, -132($fp)
  move $t2,$t1
  sw $t2, -132($fp)
  li $t3,4
  lw $t4, -132($fp)
  lw $t5, -136($fp)
  mul $t5,$t4,$t3
  sw $t5, -136($fp)
  lw $t6, -136($fp)
  lw $t7, -128($fp)
  add $t7,$t7,$t6
  sw $t7, -128($fp)
  lw $t0, -128($fp)
  lw $t1, -140($fp)
  move $t1,$t0
  sw $t1, -140($fp)
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
  lw $t2, -144($fp)
  move $t2,$v0
  sw $t2, -144($fp)
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
  lw $t4, -144($fp)
  move $t3,$t4
  lw $t5, -140($fp)
  sw $t3,0($t5)
  lw $t6, -96($fp)
  lw $t7, -148($fp)
  move $t7,$t6
  sw $t7, -148($fp)
  lw $t0, -152($fp)
  li $t0,1
  sw $t0, -152($fp)
  lw $t1, -152($fp)
  lw $t2, -148($fp)
  lw $t3, -156($fp)
  add $t3,$t2,$t1
  sw $t3, -156($fp)
  lw $t4, -156($fp)
  lw $t5, -96($fp)
  move $t5,$t4
  sw $t5, -96($fp)
  j label0
label2:
  lw $t6, -160($fp)
  li $t6,0
  sw $t6, -160($fp)
  lw $t7, -160($fp)
  lw $t0, -96($fp)
  move $t0,$t7
  sw $t0, -96($fp)
label3:
  lw $t1, -96($fp)
  lw $t2, -164($fp)
  move $t2,$t1
  sw $t2, -164($fp)
  lw $t3, -168($fp)
  li $t3,4
  sw $t3, -168($fp)
  lw $t4, -168($fp)
  lw $t5, -164($fp)
  blt $t5, $t4, label4
  j label5
label4:
  lw $t6, -96($fp)
  lw $t7, -172($fp)
  move $t7,$t6
  sw $t7, -172($fp)
  lw $t0, -176($fp)
  li $t0,1
  sw $t0, -176($fp)
  lw $t1, -176($fp)
  lw $t2, -172($fp)
  lw $t3, -180($fp)
  add $t3,$t2,$t1
  sw $t3, -180($fp)
  lw $t4, -180($fp)
  lw $t5, -184($fp)
  move $t5,$t4
  sw $t5, -184($fp)
label6:
  lw $t6, -184($fp)
  lw $t7, -188($fp)
  move $t7,$t6
  sw $t7, -188($fp)
  lw $t0, -192($fp)
  li $t0,5
  sw $t0, -192($fp)
  lw $t1, -192($fp)
  lw $t2, -188($fp)
  blt $t2, $t1, label7
  j label8
label7:
  lw $t3, -196($fp)
  addi $t3,$fp,-116
  sw $t3, -196($fp)
  lw $t4, -96($fp)
  lw $t5, -200($fp)
  move $t5,$t4
  sw $t5, -200($fp)
  li $t6,4
  lw $t7, -200($fp)
  lw $t0, -204($fp)
  mul $t0,$t7,$t6
  sw $t0, -204($fp)
  lw $t1, -204($fp)
  lw $t2, -196($fp)
  add $t2,$t2,$t1
  sw $t2, -196($fp)
  lw $t3, -196($fp)
  lw $t4, -208($fp)
  move $t4,$t3
  sw $t4, -208($fp)
  lw $t5, -212($fp)
  addi $t5,$fp,-116
  sw $t5, -212($fp)
  lw $t6, -184($fp)
  lw $t7, -216($fp)
  move $t7,$t6
  sw $t7, -216($fp)
  li $t0,4
  lw $t1, -216($fp)
  lw $t2, -220($fp)
  mul $t2,$t1,$t0
  sw $t2, -220($fp)
  lw $t3, -220($fp)
  lw $t4, -212($fp)
  add $t4,$t4,$t3
  sw $t4, -212($fp)
  lw $t5, -212($fp)
  lw $t6, -224($fp)
  move $t6,$t5
  sw $t6, -224($fp)
  lw $t7, -224($fp)
  lw $t7,0($t7)
  lw $t0, -208($fp)
  lw $t0,0($t0)
  bgt $t0, $t7, label9
  j label10
label9:
  lw $t1, -228($fp)
  addi $t1,$fp,-116
  sw $t1, -228($fp)
  lw $t2, -96($fp)
  lw $t3, -232($fp)
  move $t3,$t2
  sw $t3, -232($fp)
  li $t4,4
  lw $t5, -232($fp)
  lw $t6, -236($fp)
  mul $t6,$t5,$t4
  sw $t6, -236($fp)
  lw $t7, -236($fp)
  lw $t0, -228($fp)
  add $t0,$t0,$t7
  sw $t0, -228($fp)
  lw $t1, -228($fp)
  lw $t2, -240($fp)
  move $t2,$t1
  sw $t2, -240($fp)
  lw $t3, -240($fp)
  lw $t3,0($t3)
  lw $t4, -244($fp)
  move $t4,$t3
  sw $t4, -244($fp)
  lw $t5, -248($fp)
  addi $t5,$fp,-116
  sw $t5, -248($fp)
  lw $t6, -96($fp)
  lw $t7, -252($fp)
  move $t7,$t6
  sw $t7, -252($fp)
  li $t0,4
  lw $t1, -252($fp)
  lw $t2, -256($fp)
  mul $t2,$t1,$t0
  sw $t2, -256($fp)
  lw $t3, -256($fp)
  lw $t4, -248($fp)
  add $t4,$t4,$t3
  sw $t4, -248($fp)
  lw $t5, -248($fp)
  lw $t6, -260($fp)
  move $t6,$t5
  sw $t6, -260($fp)
  lw $t7, -264($fp)
  addi $t7,$fp,-116
  sw $t7, -264($fp)
  lw $t0, -184($fp)
  lw $t1, -268($fp)
  move $t1,$t0
  sw $t1, -268($fp)
  li $t2,4
  lw $t3, -268($fp)
  lw $t4, -272($fp)
  mul $t4,$t3,$t2
  sw $t4, -272($fp)
  lw $t5, -272($fp)
  lw $t6, -264($fp)
  add $t6,$t6,$t5
  sw $t6, -264($fp)
  lw $t7, -264($fp)
  lw $t0, -276($fp)
  move $t0,$t7
  sw $t0, -276($fp)
  lw $t2, -276($fp)
  lw $t2,0($t2)
  move $t1,$t2
  lw $t3, -260($fp)
  sw $t1,0($t3)
  lw $t4, -280($fp)
  addi $t4,$fp,-116
  sw $t4, -280($fp)
  lw $t5, -184($fp)
  lw $t6, -284($fp)
  move $t6,$t5
  sw $t6, -284($fp)
  li $t7,4
  lw $t0, -284($fp)
  lw $t1, -288($fp)
  mul $t1,$t0,$t7
  sw $t1, -288($fp)
  lw $t2, -288($fp)
  lw $t3, -280($fp)
  add $t3,$t3,$t2
  sw $t3, -280($fp)
  lw $t4, -280($fp)
  lw $t5, -292($fp)
  move $t5,$t4
  sw $t5, -292($fp)
  lw $t6, -244($fp)
  lw $t7, -296($fp)
  move $t7,$t6
  sw $t7, -296($fp)
  lw $t1, -296($fp)
  move $t0,$t1
  lw $t2, -292($fp)
  sw $t0,0($t2)
label10:
  lw $t3, -184($fp)
  lw $t4, -300($fp)
  move $t4,$t3
  sw $t4, -300($fp)
  lw $t5, -304($fp)
  li $t5,1
  sw $t5, -304($fp)
  lw $t6, -304($fp)
  lw $t7, -300($fp)
  lw $t0, -308($fp)
  add $t0,$t7,$t6
  sw $t0, -308($fp)
  lw $t1, -308($fp)
  lw $t2, -184($fp)
  move $t2,$t1
  sw $t2, -184($fp)
  j label6
label8:
  lw $t3, -96($fp)
  lw $t4, -312($fp)
  move $t4,$t3
  sw $t4, -312($fp)
  lw $t5, -316($fp)
  li $t5,1
  sw $t5, -316($fp)
  lw $t6, -316($fp)
  lw $t7, -312($fp)
  lw $t0, -320($fp)
  add $t0,$t7,$t6
  sw $t0, -320($fp)
  lw $t1, -320($fp)
  lw $t2, -96($fp)
  move $t2,$t1
  sw $t2, -96($fp)
  j label3
label5:
  lw $t3, -324($fp)
  li $t3,0
  sw $t3, -324($fp)
  lw $t4, -324($fp)
  lw $t5, -96($fp)
  move $t5,$t4
  sw $t5, -96($fp)
label11:
  lw $t6, -96($fp)
  lw $t7, -328($fp)
  move $t7,$t6
  sw $t7, -328($fp)
  lw $t0, -332($fp)
  li $t0,5
  sw $t0, -332($fp)
  lw $t1, -332($fp)
  lw $t2, -328($fp)
  blt $t2, $t1, label12
  j label13
label12:
  lw $t3, -336($fp)
  addi $t3,$fp,-116
  sw $t3, -336($fp)
  lw $t4, -96($fp)
  lw $t5, -340($fp)
  move $t5,$t4
  sw $t5, -340($fp)
  li $t6,4
  lw $t7, -340($fp)
  lw $t0, -344($fp)
  mul $t0,$t7,$t6
  sw $t0, -344($fp)
  lw $t1, -344($fp)
  lw $t2, -336($fp)
  add $t2,$t2,$t1
  sw $t2, -336($fp)
  lw $t3, -336($fp)
  lw $t4, -348($fp)
  move $t4,$t3
  sw $t4, -348($fp)
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
  lw $a0, -348($fp)
  lw $a0,0($a0)
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
  lw $t5, -96($fp)
  lw $t6, -352($fp)
  move $t6,$t5
  sw $t6, -352($fp)
  lw $t7, -356($fp)
  li $t7,1
  sw $t7, -356($fp)
  lw $t0, -356($fp)
  lw $t1, -352($fp)
  lw $t2, -360($fp)
  add $t2,$t1,$t0
  sw $t2, -360($fp)
  lw $t3, -360($fp)
  lw $t4, -96($fp)
  move $t4,$t3
  sw $t4, -96($fp)
  j label11
label13:
  lw $t5, -364($fp)
  addi $t5,$fp,-116
  sw $t5, -364($fp)
  lw $t6, -364($fp)
  lw $t7, -48($fp)
  move $t7,$t6
  sw $t7, -48($fp)
  lw $t0, -368($fp)
  addi $t0,$fp,-116
  sw $t0, -368($fp)
  lw $t1, -368($fp)
  lw $t2, -88($fp)
  move $t2,$t1
  sw $t2, -88($fp)
  lw $t3, -372($fp)
  li $t3,0
  sw $t3, -372($fp)
  lw $t4, -372($fp)
  lw $t5, -96($fp)
  move $t5,$t4
  sw $t5, -96($fp)
label14:
  lw $t6, -96($fp)
  lw $t7, -376($fp)
  move $t7,$t6
  sw $t7, -376($fp)
  lw $t0, -380($fp)
  li $t0,5
  sw $t0, -380($fp)
  lw $t1, -380($fp)
  lw $t2, -376($fp)
  blt $t2, $t1, label15
  j label16
label15:
  lw $t3, -96($fp)
  lw $t4, -384($fp)
  move $t4,$t3
  sw $t4, -384($fp)
  lw $t5, -388($fp)
  li $t5,3
  sw $t5, -388($fp)
  lw $t6, -388($fp)
  lw $t7, -384($fp)
  blt $t7, $t6, label17
  j label18
label17:
  lw $t0, -392($fp)
  addi $t0,$fp,-48
  sw $t0, -392($fp)
  lw $t1, -96($fp)
  lw $t2, -396($fp)
  move $t2,$t1
  sw $t2, -396($fp)
  li $t3,4
  lw $t4, -396($fp)
  lw $t5, -400($fp)
  mul $t5,$t4,$t3
  sw $t5, -400($fp)
  lw $t6, -400($fp)
  lw $t7, -392($fp)
  add $t7,$t7,$t6
  sw $t7, -392($fp)
  lw $t0, -392($fp)
  lw $t1, -404($fp)
  move $t1,$t0
  sw $t1, -404($fp)
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
  lw $a0, -404($fp)
  lw $a0,0($a0)
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
  lw $t2, -408($fp)
  addi $t2,$fp,-88
  sw $t2, -408($fp)
  lw $t3, -96($fp)
  lw $t4, -412($fp)
  move $t4,$t3
  sw $t4, -412($fp)
  li $t5,4
  lw $t6, -412($fp)
  lw $t7, -416($fp)
  mul $t7,$t6,$t5
  sw $t7, -416($fp)
  lw $t0, -416($fp)
  lw $t1, -408($fp)
  add $t1,$t1,$t0
  sw $t1, -408($fp)
  lw $t2, -408($fp)
  lw $t3, -420($fp)
  move $t3,$t2
  sw $t3, -420($fp)
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
  lw $a0, -420($fp)
  lw $a0,0($a0)
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
  j label19
label18:
  lw $t4, -424($fp)
  addi $t4,$fp,-88
  sw $t4, -424($fp)
  lw $t5, -96($fp)
  lw $t6, -428($fp)
  move $t6,$t5
  sw $t6, -428($fp)
  li $t7,4
  lw $t0, -428($fp)
  lw $t1, -432($fp)
  mul $t1,$t0,$t7
  sw $t1, -432($fp)
  lw $t2, -432($fp)
  lw $t3, -424($fp)
  add $t3,$t3,$t2
  sw $t3, -424($fp)
  lw $t4, -424($fp)
  lw $t5, -436($fp)
  move $t5,$t4
  sw $t5, -436($fp)
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
  lw $a0, -436($fp)
  lw $a0,0($a0)
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
label19:
  lw $t6, -96($fp)
  lw $t7, -440($fp)
  move $t7,$t6
  sw $t7, -440($fp)
  lw $t0, -444($fp)
  li $t0,1
  sw $t0, -444($fp)
  lw $t1, -444($fp)
  lw $t2, -440($fp)
  lw $t3, -448($fp)
  add $t3,$t2,$t1
  sw $t3, -448($fp)
  lw $t4, -448($fp)
  lw $t5, -96($fp)
  move $t5,$t4
  sw $t5, -96($fp)
  j label14
label16:
  lw $t6, -452($fp)
  li $t6,0
  sw $t6, -452($fp)
  lw $t7, -452($fp)
  move $v0, $t7
  sw $t7, -452($fp)
  addi $sp, $sp, 416
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
