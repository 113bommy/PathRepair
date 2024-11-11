n = int(input())

def check(n):
    key7 = 0
    key4 = 0
    for i in range(int(n//7)+1):
        j = n - i*7
        if j%4==0:
            key7 = i
            key4 = int(j/4)
    if key4==0 and key7==0:
        return -1
    return '7'*key7+'4'*key4

print(check(n))

