h, w = map(int, input().split())

w_cost = [int(input()) for i in range(w)]
h_cost = [int(input()) for i in range(h)]

w_cost = sorted(w_cost, reverse = True)
h_cost = sorted(h_cost, reverse = True)
w_cnt = 0
h_cnt = 0
ans = 0

while True:
    if not w_cost:
        ans += sum(h_cost)   
        break
    elif not h_cost:
        ans += sum(w_cost)
        break
    elif w_cost[-1] < h_cost[-1]:
        ans += w_cost[-1] * (h+1-h_cnt)
        w_cnt += 1
        del w_cost[-1]
    else:
        ans += h_cost[-1] * (w+1-w_cnt)
        h_cnt += 1
        del h_cost[-1]
        
print(ans)