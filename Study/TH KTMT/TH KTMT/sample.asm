include irvine32.inc
.386
.model flat, stdcall
.stack 4096
ExitProcess proto, dwExitCode:dword
.data
	x dd 25
	y dd 10
	a dd ?
	kq db "Ket qua: "
.code
main proc
	push y
	push x

	call sum
	mov a, eax 

	lea edx, kq
	call writestring

	mov eax, a
	call writeDec
	call crlf

invoke ExitProcess, 0
main endp
sum proc
	push ebp
	mov ebp, esp

	mov eax, [ebp+8]
	sub eax, [ebp+12]

	pop ebp
	ret 8
sum endp
end main

