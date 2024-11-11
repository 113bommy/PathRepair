n = int(input())
print(n)
k = 0
st = ""
if n % 2 == 1:
    while n != 3:
        k += 1
        st += "2 "
        n -= 2
else:
    while n != 0:
        k += 1
        st += "2 "
        n -= 2
if n == 3:
    st += "3"
    print(k+1)
    print(st)
else:
    print(k)
    print(st)