def is_odd(a):
    return bool(a&1)

def main():
    n = int(input())
    even = 0
    odd = 0
    for a in map(int,input().split()):
        if is_odd(a):
            odd += 1
        else:
            even += 1
    cnt = min(even,odd)
    if odd>even:
        odd /= 3
        cnt += odd 
    print(int(cnt))
main()
