w, count = input(), 0

while True:
    line = input()
    if line == 'END_OF_TEXT':
        break
    count += line.split().count(w)

print(count)