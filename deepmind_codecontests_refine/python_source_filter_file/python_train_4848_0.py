import sys
n, m = map(int, input().split())

file_name_list = []
for _ in range(n):
    file_name_list.append(input())

file_pos_to_delete = map(int, input().split())

file_to_delete_list = [file_name_list[pos - 1] for pos in file_pos_to_delete]
l = len(file_to_delete_list[0])
if any(len(e) != l for e in file_to_delete_list):
    print('No')
    sys.exit(0)


pattern = []
for i in range(l):
    pattern.append(file_to_delete_list[0][i])
    for j in range(1, m):
        if pattern[-1] != file_to_delete_list[j][i]:
            pattern[-1] = '?'
            break

for i in range(n):
    w = file_name_list[i]
    if i + 1 not in file_pos_to_delete and len(w) == l and all(w[k] == pattern[k] or pattern[k] != '?' for k in range(l)):
        print('No')
        sys.exit(0)

print('Yes')
print(''.join(pattern))