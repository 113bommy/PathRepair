from statistics import pstdev

while True:
    if input() == 0: break
    v_list = (int(x) for x in input().split())
    print(pstdev(v_list))