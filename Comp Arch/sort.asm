.386
.model flat
.code
public _sort 
_sort proc
push ebp
mov ebp,esp
START:
	mov esi,[ebp+8]
	xor cl,cl
NEXT:
	mov al,[esi]
	mov bl,[esi+1]
	cmp bl,al
	jge SKIP 
	mov [esi],bl
	mov [esi+1],al
	mov cl,1
SKIP:
	inc esi
	mov dl,[esi+1]
	cmp dl,0
	je FINISHED
	jmp NEXT
FINISHED: 
	cmp cl,1
	je START
	pop ebp
	ret
	_sort endp
	end