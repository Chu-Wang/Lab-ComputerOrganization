 .text
#################################################################################
#������ʵ��0x80��ʼ��8���ֵ�Ԫ�Ľ�������,�˳������mars mips������������,�ֵ�ַ0x80
#����ʱ�뽫Mars Setting�е�Memory Configuration����ΪCompact��data at address 0
#
#################################################################################
 .text
sort_init:
 addi $s0,$0,-1
 addi $s1,$0,0
 sw $s0,128($s1)
 addi $s0,$s0,1
 addi $s1,$s1,4
 sw $s0,128($s1)
 addi $s0,$s0,1
 addi $s1,$s1,4
 sw $s0,128($s1)
 addi $s0,$s0,1
 addi $s1,$s1,4
 sw $s0,128($s1)
 addi $s0,$s0,1
 addi $s1,$s1,4
 sw $s0,128($s1)
 addi $s0,$s0,1
 addi $s1,$s1,4
 sw $s0,128($s1)
 addi $s0,$s0,1
 addi $s1,$s1,4
 sw $s0,128($s1)
 addi $s0,$s0,1
 addi $s1,$s1,4
 sw $s0,128($s1)
 
 add $s0,$zero,$zero   
 addi $s1,$zero,28   #��������
sort_loop:
 lw $s3,128($s0)     
 lw $s4,128($s1)
 slt $t0,$s3,$s4
 beq $t0,$0,sort_next   #��������
 sw $s3, 128($s1)
 sw $s4, 128($s0)   
sort_next:
 addi $s1, $s1, -4   
 bne $s0, $s1, sort_loop  
 
 
 addi $s0,$s0,4
 addi $s1,$zero,28
 bne $s0, $s1, sort_loop
 addi   $v0,$zero,10         # system call for exit
 syscall                  # we are out of here.   
