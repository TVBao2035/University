; AddTwo.asm - adds two 32-bit integers.
; Chapter 3 example
INCLUDE Irvine32.inc
.386
.model flat,stdcall
.stack 4096
ExitProcess proto,dwExitCode:dword
.data
	a dword 10
	b dword 50
	k dword 5
.code
main5 proc
	mov eax,3
	mul a
	mov ebx, eax
	mov eax,2
	mul b
	sub eax, ebx
	mov k, eax
	call writedec
	call crlf
	invoke ExitProcess,0
main5 endp
end main5