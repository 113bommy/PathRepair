n = int(input())
s = list(input())
t = list(input())


if not sorted(s) == sorted(t):
    print(-1)
    exit()


moves = []

# Remove common prefix
for i in range(n):
    if s[i] == t[i]:
        print("matched upto " + ''.join(s[:i+1]))
        continue

    

    else:
        for j in range(i, n):
            if s[j] == t[i]:
                break

        moves.extend((list(range(i+1, j+1)))[::-1])
        s = s[:i] + [s[j]] + s[i:j] + (s[j+1:] if j+1 < n else [''])

        print(''.join(s))

print(len(moves))
print(' '.join(map(str, moves)))



