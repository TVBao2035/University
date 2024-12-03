; AddTwo.asm - adds two 32-bit integers.
; Chapter 3 example
INCLUDE Irvine32.inc
.386
.model flat,stdcall
.stack 4096
ExitProcess proto,dwExitCode:dword
.data
	tb1 byte 13,10, "Nhap mot ky tu : "
	tb2 byte 13,10, "Nam ky tu ke : "
	kytu byte ?
.code
main2323 proc
	mov edx, offset tb1
	call writestring
	call readchar
	mov kytu, al
	mov edx, offset tb2
	call writestring
	mov al, kytu
	inc al
	mov ecx, 5
lap2:
	jecxz ketthuc
	call writechar
	dec ecx
	inc al
	push eax
	pop eax
	mov al, 10
	call writechar
	mov al, 8
	call writechar
	jmp lap2
ketthuc:
	call writedec
	call crlf
	invoke ExitProcess,0
main2323 endp
end main2323