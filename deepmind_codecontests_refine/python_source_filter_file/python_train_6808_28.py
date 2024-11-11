def func(n):
    ans = ''
    i = 0
    while i < len(n):
        if n[i] == '-':
            if n[i+1] == '.':
                ans += '1'
            elif n[i+1] == '-':
                ans += '2'
            i += 1
        elif n[i] == '.':
            ans += '0'
        i += 1
    print(int(ans))
n = input()
func(n)