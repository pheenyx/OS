	.file	"gesamt.c"
	.text
	.globl	add
	.type	add, @function
add:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	%edi, -20(%rbp)
	movl	%esi, -24(%rbp)
	movl	-24(%rbp), %eax
	movl	-20(%rbp), %edx
	addl	%edx, %eax
	movl	%eax, -4(%rbp)
	movl	-4(%rbp), %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	add, .-add
	.globl	sub
	.type	sub, @function
sub:
.LFB1:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	%edi, -20(%rbp)
	movl	%esi, -24(%rbp)
	movl	-24(%rbp), %eax
	movl	-20(%rbp), %edx
	movl	%edx, %ecx
	subl	%eax, %ecx
	movl	%ecx, %eax
	movl	%eax, -4(%rbp)
	movl	-4(%rbp), %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	sub, .-sub
	.globl	mult
	.type	mult, @function
mult:
.LFB2:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	%edi, -20(%rbp)
	movl	%esi, -24(%rbp)
	movl	-20(%rbp), %eax
	imull	-24(%rbp), %eax
	movl	%eax, -4(%rbp)
	movl	-4(%rbp), %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	mult, .-mult
	.globl	div
	.type	div, @function
div:
.LFB3:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	%edi, -20(%rbp)
	movl	%esi, -24(%rbp)
	movl	-20(%rbp), %eax
	movl	%eax, %edx
	sarl	$31, %edx
	idivl	-24(%rbp)
	movl	%eax, -4(%rbp)
	movl	-4(%rbp), %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3:
	.size	div, .-div
	.globl	rest
	.type	rest, @function
rest:
.LFB4:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	%edi, -20(%rbp)
	movl	-20(%rbp), %ecx
	movl	$1717986919, %edx
	movl	%ecx, %eax
	imull	%edx
	sarl	%edx
	movl	%ecx, %eax
	sarl	$31, %eax
	subl	%eax, %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	movl	%ecx, %edx
	subl	%eax, %edx
	movl	%edx, %eax
	movl	%eax, -4(%rbp)
	movl	-4(%rbp), %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE4:
	.size	rest, .-rest
	.globl	rest_add
	.type	rest_add, @function
rest_add:
.LFB5:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	.cfi_offset 3, -24
	movl	%edi, -28(%rbp)
	movl	%esi, -32(%rbp)
	movl	-32(%rbp), %eax
	movl	-28(%rbp), %edx
	leal	(%rdx,%rax), %ecx
	movl	$1717986919, %edx
	movl	%ecx, %eax
	imull	%edx
	sarl	%edx
	movl	%ecx, %eax
	sarl	$31, %eax
	movl	%edx, %ebx
	subl	%eax, %ebx
	movl	%ebx, %eax
	movl	%eax, -12(%rbp)
	movl	-12(%rbp), %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	movl	%ecx, %edx
	subl	%eax, %edx
	movl	%edx, %eax
	movl	%eax, -12(%rbp)
	movl	-12(%rbp), %eax
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE5:
	.size	rest_add, .-rest_add
	.globl	basis
	.type	basis, @function
basis:
.LFB6:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	$5, %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	basis, .-basis
	.section	.rodata
	.align 8
.LC0:
	.string	"bitte einen int-Parameter eingeben! "
.LC1:
	.string	"%d"
	.text
	.globl	getarg
	.type	getarg, @function
getarg:
.LFB7:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movl	$.LC0, %edi
	call	puts
	leaq	-4(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC1, %edi
	movl	$0, %eax
	call	__isoc99_scanf
	movl	-4(%rbp), %edx
	movq	-24(%rbp), %rax
	movl	%edx, (%rax)
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7:
	.size	getarg, .-getarg
	.section	.rodata
	.align 8
.LC2:
	.string	"bitte zwei int-Parameter eingeben! "
.LC3:
	.string	"%d %d"
	.text
	.globl	get2args
	.type	get2args, @function
get2args:
.LFB8:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movl	$.LC2, %edi
	call	puts
	leaq	-4(%rbp), %rdx
	leaq	-8(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC3, %edi
	movl	$0, %eax
	call	__isoc99_scanf
	movl	-8(%rbp), %edx
	movq	-24(%rbp), %rax
	movl	%edx, (%rax)
	movl	-4(%rbp), %edx
	movq	-32(%rbp), %rax
	movl	%edx, (%rax)
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8:
	.size	get2args, .-get2args
	.section	.rodata
.LC4:
	.string	"%s () = %d \n\n"
	.text
	.globl	puterg0
	.type	puterg0, @function
puterg0:
.LFB9:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movl	%esi, -12(%rbp)
	movl	-12(%rbp), %edx
	movq	-8(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC4, %edi
	movl	$0, %eax
	call	printf
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9:
	.size	puterg0, .-puterg0
	.section	.rodata
.LC5:
	.string	"%s ( %d ) = %d \n\n"
	.text
	.globl	puterg1
	.type	puterg1, @function
puterg1:
.LFB10:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movl	%esi, -12(%rbp)
	movl	%edx, -16(%rbp)
	movl	-16(%rbp), %ecx
	movl	-12(%rbp), %edx
	movq	-8(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC5, %edi
	movl	$0, %eax
	call	printf
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE10:
	.size	puterg1, .-puterg1
	.section	.rodata
.LC6:
	.string	"%s ( %d, %d ) = %d \n\n"
	.text
	.globl	puterg2
	.type	puterg2, @function
puterg2:
.LFB11:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -8(%rbp)
	movl	%esi, -12(%rbp)
	movl	%edx, -16(%rbp)
	movl	%ecx, -20(%rbp)
	movl	-20(%rbp), %esi
	movl	-16(%rbp), %ecx
	movl	-12(%rbp), %edx
	movq	-8(%rbp), %rax
	movl	%esi, %r8d
	movq	%rax, %rsi
	movl	$.LC6, %edi
	movl	$0, %eax
	call	printf
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE11:
	.size	puterg2, .-puterg2
	.section	.rodata
.LC7:
	.string	"Gewuenschte Operation?   "
.LC8:
	.string	"   1: add    2: sub      "
.LC9:
	.string	"   3: mult   4: div      "
.LC10:
	.string	"   5: rest   6: rest_add "
.LC11:
	.string	"   7: basis              "
.LC12:
	.string	"  99: Programmende       \n"
.LC13:
	.string	"add"
.LC14:
	.string	"sub"
.LC15:
	.string	"mult"
.LC16:
	.string	"div"
.LC17:
	.string	"rest"
.LC18:
	.string	"rest_add"
.LC19:
	.string	"basis"
	.text
	.globl	main
	.type	main, @function
main:
.LFB12:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movl	$0, -8(%rbp)
.L32:
	movl	$.LC7, %edi
	call	puts
	movl	$.LC8, %edi
	call	puts
	movl	$.LC9, %edi
	call	puts
	movl	$.LC10, %edi
	call	puts
	movl	$.LC11, %edi
	call	puts
	movl	$.LC12, %edi
	call	puts
	leaq	-12(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC1, %edi
	movl	$0, %eax
	call	__isoc99_scanf
	movl	-12(%rbp), %eax
	cmpl	$4, %eax
	je	.L25
	cmpl	$4, %eax
	jg	.L30
	cmpl	$2, %eax
	je	.L23
	cmpl	$2, %eax
	jg	.L24
	cmpl	$1, %eax
	je	.L22
	jmp	.L21
.L30:
	cmpl	$6, %eax
	je	.L27
	cmpl	$6, %eax
	jl	.L26
	cmpl	$7, %eax
	je	.L28
	cmpl	$99, %eax
	je	.L29
	jmp	.L21
.L22:
	leaq	-16(%rbp), %rdx
	leaq	-20(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	get2args
	movl	-16(%rbp), %edx
	movl	-20(%rbp), %eax
	movl	%edx, %esi
	movl	%eax, %edi
	call	add
	movl	%eax, -4(%rbp)
	movl	-16(%rbp), %edx
	movl	-20(%rbp), %eax
	movl	-4(%rbp), %ecx
	movl	%eax, %esi
	movl	$.LC13, %edi
	call	puterg2
	jmp	.L31
.L23:
	leaq	-16(%rbp), %rdx
	leaq	-20(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	get2args
	movl	-16(%rbp), %edx
	movl	-20(%rbp), %eax
	movl	%edx, %esi
	movl	%eax, %edi
	call	sub
	movl	%eax, -4(%rbp)
	movl	-16(%rbp), %edx
	movl	-20(%rbp), %eax
	movl	-4(%rbp), %ecx
	movl	%eax, %esi
	movl	$.LC14, %edi
	call	puterg2
	jmp	.L31
.L24:
	leaq	-16(%rbp), %rdx
	leaq	-20(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	get2args
	movl	-16(%rbp), %edx
	movl	-20(%rbp), %eax
	movl	%edx, %esi
	movl	%eax, %edi
	call	mult
	movl	%eax, -4(%rbp)
	movl	-16(%rbp), %edx
	movl	-20(%rbp), %eax
	movl	-4(%rbp), %ecx
	movl	%eax, %esi
	movl	$.LC15, %edi
	call	puterg2
	jmp	.L31
.L25:
	leaq	-16(%rbp), %rdx
	leaq	-20(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	get2args
	movl	-16(%rbp), %edx
	movl	-20(%rbp), %eax
	movl	%edx, %esi
	movl	%eax, %edi
	call	div
	movl	%eax, -4(%rbp)
	movl	-16(%rbp), %edx
	movl	-20(%rbp), %eax
	movl	-4(%rbp), %ecx
	movl	%eax, %esi
	movl	$.LC16, %edi
	call	puterg2
	jmp	.L31
.L26:
	leaq	-20(%rbp), %rax
	movq	%rax, %rdi
	call	getarg
	movl	-20(%rbp), %eax
	movl	%eax, %edi
	call	rest
	movl	%eax, -4(%rbp)
	movl	-20(%rbp), %eax
	movl	-4(%rbp), %edx
	movl	%eax, %esi
	movl	$.LC17, %edi
	call	puterg1
	jmp	.L31
.L27:
	leaq	-16(%rbp), %rdx
	leaq	-20(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	get2args
	movl	-16(%rbp), %edx
	movl	-20(%rbp), %eax
	movl	%edx, %esi
	movl	%eax, %edi
	call	rest_add
	movl	%eax, -4(%rbp)
	movl	-16(%rbp), %edx
	movl	-20(%rbp), %eax
	movl	-4(%rbp), %ecx
	movl	%eax, %esi
	movl	$.LC18, %edi
	call	puterg2
	jmp	.L31
.L28:
	movl	$0, %eax
	call	basis
	movl	%eax, -4(%rbp)
	movl	-4(%rbp), %eax
	movl	%eax, %esi
	movl	$.LC19, %edi
	call	puterg0
	jmp	.L31
.L29:
	movl	$1, -8(%rbp)
	jmp	.L31
.L21:
	nop
.L31:
	cmpl	$0, -8(%rbp)
	je	.L32
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE12:
	.size	main, .-main
	.ident	"GCC: (Ubuntu/Linaro 4.7.2-2ubuntu1) 4.7.2"
	.section	.note.GNU-stack,"",@progbits
