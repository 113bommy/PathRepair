q = int(input())
len_of_str = [0] * int(1e5)
len_of_str[0] = 75
left_part = 'What are you doing while sending "'
start_str = 'What are you doing at the end of the world? Are you busy? Will you save us?'
mid_part = '"? Are you busy? Will you send "'
right_part = '"?'
left_len = 34
mid_len = 32
right_len = 2
ans = ''
for i in range(1, int(1e5)):
    len_of_str[i] = min(1e18, left_len + len_of_str[i - 1] + mid_len + len_of_str[i - 1] + right_len)
    
for i in range(q): 
    n, k = map(int, input().split())
    ind = k
    while (n >= 0):
        if n == 0 and ind > len_of_str[0]:
            ans += '.'
            break
        elif n == 0:
            ans += start_str[ind - 1]
            break
        #print(n, ind)
        if ind <= left_len:
            ans += left_part[ind - 1]
            break
        ind -= left_len
        if ind <= len_of_str[n - 1]:
            n -= 1
            continue
        ind -= len_of_str[n - 1]
        if ind <= mid_len:
            ans += mid_part[ind - 1]
            break
        ind -= mid_len
        if ind <= len_of_str[n - 1]:
            n -= 1
            continue
        ind -= len_of_str[n - 1]
        if ind > 2:
            ans += '.'
        else:
            ans += right_part[ind - 1]
        break
    #print('ans =', ans)
print(ans)