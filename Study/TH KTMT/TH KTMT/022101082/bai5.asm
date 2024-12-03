; AddTwo.asm - adds two 32-bit integers.
; Chapter 3 example
INCLUDE Irvine32.inc
.386
.model flat,stdcall
.stack 4096
ExitProcess proto,dwExitCode:dword
.data
	 sobichia dword 100
	 sochia dword 15
	 thuong dword ?
.code
main22 proc
	mov eax, sobichia
	mov ebx, sochia
	xor ecx, ecx
while1:
	cmp eax, ebx
	jl endw
	inc ecx
	sub eax, ebx
	jmp while1
endw:
	mov thuong, ecx
	mov eax, ecx
	call writedec
	call crlf
	invoke ExitProcess,0
main22 endp
end main22