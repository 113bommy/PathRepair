S = input().replace('eraser', '').replace('erase', '')
chk = S.replace('dreamer', '').replace('dream', '')
print(['YES', 'NO'][len(chk) > 0])