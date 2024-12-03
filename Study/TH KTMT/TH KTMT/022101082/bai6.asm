; AddTwo.asm - adds two 32-bit integers.
; Chapter 3 example
INCLUDE Irvine32.inc
.386
.model flat,stdcall
.stack 4096
ExitProcess proto,dwExitCode:dword
.data
	thuaso1 dword 100
	thuaso2 dword 5
	tich dword ?
.code
main23 proc
	xor eax, eax
	mov ebx, thuaso1
	mov ecx, thuaso2
while2:
	jecxz endw2
	add eax, ebx
	dec ecx
	jmp while2
endw2:
	mov tich, eax
	call writedec
	call crlf
	invoke ExitProcess,0
main23 endp
end main23