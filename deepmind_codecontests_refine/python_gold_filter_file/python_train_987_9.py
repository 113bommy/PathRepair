# ��� � ���� ���������!!!!!!

# ����
# ����������� �� ��������� �(logn * n)
# ������� ��������� � �������� ��� ����� ������
# ������ ����� ����� ������ �� ������ ������� �� ����������� ���������� ��������
# ������ ������������ �� ���� ����
#
#
# ��� ���????
# ������ ���� ���������� �������� � ������� ���������!!!
# � ����� ��� ������??????
# ������ ����� ����� � ����� ���� ��������� � ����������
# � � ������� ��� �������� ��������� ����� ����� �� �(1) !!!!

n, d = tuple(map(int, input().split()))
m, s = [0] * n, [0] * n
ms = [0] * n
for i in range(n):
    m[i], s[i] = tuple(map(int, input().split()))
    ms[i] = m[i], s[i]
    
suffix = [0] * n
postfix = [0] * n
alsum = sum(s)
ms.sort()
for i in range(1, n):
    postfix[i] = postfix[i - 1] + ms[i - 1][1]
    
for i in range(n - 2, -1, -1):
    suffix[i] = suffix[i + 1] + ms[i + 1][1]

friends = []
for i in range(n):
    # �������� ��������
    left = i - 1
    right = n - 1
    while right - left > 1:
        middle = (right + left) // 2
        if ms[middle][0] >= ms[i][0] + d:
            right = middle
        else:
            left = middle
    rich = right
    if ms[rich][0] >= ms[i][0] + d: rich -= 1
    #print(rich)
    friends.append(alsum - postfix[i] - suffix[rich])
    
print(max(friends))
    
        
    