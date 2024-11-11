n = int(input())
a = int(input())
b = int(input())
c = int(input())
a2 = b-c
if a2 >= a or n < b:
        print(n // a)
else:
        ans = 0
        ans += (n-c) // (b-c)
        n -= ans * (b-c)
        ans += n // a
        print(ans)
