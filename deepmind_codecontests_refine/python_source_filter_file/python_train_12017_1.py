st = input()
copy = st.split('=')
if copy[0].count('|') + 2 == copy[1].count('|'):
    st = '|' + st[:len(st) - 1]
elif copy[0].count('|')  == copy[1].count('|') + 2:
    if copy[0].split('+')[0].count('|') < 2:
        st = f'{copy[0][:-1]} = {copy[1]}|'
    else:
	    st = st[1:] + '|'
elif copy[0].count('|') != copy[1].count('|'):
	st = 'Impossible'
print(st)	