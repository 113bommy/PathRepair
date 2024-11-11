n, m = map(int, input().split(" "))

messages = []

months = [0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]

while True:
    try:
        s = input()
        messages.append(s)

    except:
        break

# print(messages)

length = len(messages)

pref = [0]

for i in range(1, 13):
    pref.append(pref[i - 1] + months[i])

# print(pref)

got = False
now = 0
prev = 0
store = []

for message in messages:
    date = int(message[8:10]) + pref[int(message[5:7]) - 1]
    time = date * 24 * 60 * 60 + int(message[11:13]) * 60 * 60 + int(message[14:16]) * 60 + int(message[17:19])
    store.append(time)

    if now < m - 1:
        now += 1
        continue

    else:
        prev = now - (m - 1)

    if (store[now] - store[prev]) < n:
        print(message[:19])
        got = True
        break

    now += 1

if not got:
    print(-1)
