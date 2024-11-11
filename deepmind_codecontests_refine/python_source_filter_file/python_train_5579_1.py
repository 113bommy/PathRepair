def main():
    n, m = map(int, input().split())
    for i in range(m):
        numbers = tuple(map(int, input().split()))
        s = set()
        is_safe = False
        for t in numbers:
            if -t in s:
                is_safe = True
                break
            s.add(t)
        if is_safe == False:
            print("YES")
            return
    print("NO")

main()