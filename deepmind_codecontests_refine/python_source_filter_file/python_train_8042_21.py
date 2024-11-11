def multiply(s, num):

    if(num == 1):
        return s
    if(num == 0):
        return ""
    a = multiply(s, int(num/2))
    a = a + a
    if (num % 2 == 1):
        a = a + s
    return a


t = input()
t = int(t)
for i in range(t):
    ans = ""
    n = input()
    n= int(n)
    yet = multiply("8", (n/4))
    if n % 4 !=0:
        yet += "8"
    count = len(yet)
    ans = multiply("9", (n - count)) + yet
    print(ans)