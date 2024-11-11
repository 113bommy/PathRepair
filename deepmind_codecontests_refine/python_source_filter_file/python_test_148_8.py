N = int(input())
for i in range(N):
    w, h = map(int, input().split())
    max_area = 0
    l1 = list(map(int, input().split()))
    l2 = list(map(int, input().split()))
    l3 = list(map(int, input().split()))
    l4 = list(map(int, input().split()))
    max_area = max(max_area, (l1[-1] - l1[0]) * h)
    max_area = max(max_area, (l2[-1] - l2[0]) * h)
    max_area = max(max_area, (l3[-1] - l3[0]) * w)
    max_area = max(max_area, (l4[-1] - l4[0]) * w)
    print(max_area)