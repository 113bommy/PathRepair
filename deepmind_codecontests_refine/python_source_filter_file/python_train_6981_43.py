notice = int(input())
record = [[[0] * 10 for i in range(3)] for j in range(4)]

for _ in range(notice):
    b, f, r, v = map(int, input().split())
    record[b-1][f-1][r-1] += v

ans = ('\n' + '#' * 20 + '\n').join([ '\n'.join([' '.join(map(str, floor)) for floor in building]) for building in record])
print(ans)
