; AddTwo.asm - adds two 32-bit integers.
; Chapter 3 example
INCLUDE Irvine32.inc
.386
.model flat,stdcall
.stack 4096
ExitProcess proto,dwExitCode:dword
.data
	tb1 byte 13,10, "Nhap chieu dai: ", 0
	tb2 byte 13,10, "Nhap chieu rong: ", 0
	tb3 byte 13,10, "Chu vi: ", 0
	tb4 byte 13,10, "Dien tich: ", 0
	chieudai dword  ?
	chieurong dword ?
	chuvi dword		?
	dientich dword  ?
.code
main proc
	mov edx, offset tb1
	call writestring
	call readdec
	mov chieudai, eax
	mov edx, offset tb2
	call writestring
	call readdec
	mov chieurong, eax
	mov eax, chieudai
	mov eax, chieurong
	shl eax, 1
	mov chuvi, eax
	mov eax, chieudai
	mul chieurong
	mov dientich, eax
	call writedec
	call crlf
	invoke ExitProcess,0
main endp
end main