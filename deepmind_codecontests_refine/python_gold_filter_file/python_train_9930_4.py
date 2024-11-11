n, m = map(int, input().split())
all_one = True
all_one_except = True
one_except = False
all_two = True
visited = [False] * (n + 1)
st = [0] * (n + 1)
for i in range(m):
    a, b = map(int, input().split())
    st[a] += 1
    st[b] += 1
for i in range(1, n + 1):
    if st[i] != 2:
        all_two = False
    if st[i] > 2:
        all_one = False
    if st[i] > 1:
        if one_except:
            all_one_except = False
        else:
            one_except = True
    if not (all_one or all_two or all_one_except):
        break
if all_two:
    print('ring topology')
elif all_one:
    print('bus topology')
elif all_one_except:
    print('star topology')
else:
    print('unknown topology')
