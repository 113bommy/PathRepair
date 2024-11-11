n_d = input("")
n_d_list = list(n_d.split())
n, d = int(n_d_list[0]), int(n_d_list[1])
time_strng = input("")
time_strng_list = list(time_strng.split())
time = []
for i in range(len(time_strng_list)):
    time.append(int(time_strng_list[i]))
mi = 0
jokes = 0

for j in range(n):
    mi += time[j]

    if j < n-1:
        jokes += 2
        mi += 10
    else:
        jokes += (d-mi)//5


if mi > d:
    print(-1)
else:
    print(j)