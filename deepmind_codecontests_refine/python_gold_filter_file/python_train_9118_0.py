import sys

pb_raw = sys.stdin.readlines()

in_len = int(pb_raw[0].strip())

pb_str = pb_raw[1].strip()
pb_str = pb_str.replace('0', ' ')

tmp = [str(len(chunk)) for chunk in pb_str.split(' ')]
sol = ''.join(tmp)

sys.stdout.writelines(sol)
