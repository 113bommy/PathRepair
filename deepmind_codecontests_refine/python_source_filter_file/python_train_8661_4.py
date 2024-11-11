def main():
    n = int(input())
    for i in range(n):
        s = input()
        if '0' not in s:
            print('cyan')
            continue
        s = s.replace('0','',1)
        print(s)
        total = 0
        even = False
        for j in s:
            total += int(j)
            if int(j)%2 == 0:
                even = True
        if total%3 != 0:
            print('cyan')
            continue
        if not even:
            print('cyan')
            continue

        print('red')

main()
