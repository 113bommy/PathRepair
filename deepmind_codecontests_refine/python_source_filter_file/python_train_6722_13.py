n = int(input())

la = 1
a = 1
lb = n
b = n

while(a <= b):
    a = a + 1
    b = n/a

    if(n % a == 0 and n!=2):
        la = a
        lb = n /la


print(la, int(n/la))