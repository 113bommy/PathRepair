
def luck(n):
    hh = n // 60
    mm = n % 60
    if hh % 10 == 7 or mm % 10 == 7:
        return True
    return False


x = int(input())

hh, mm = map(int, input().split())

cur = hh * 60 + mm

ans = 0

while luck(cur) == False:
    cur -= x
    if cur < 0: cur += 60 * 2400
    
    ans += 1
    
print(ans)