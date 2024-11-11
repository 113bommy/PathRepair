line = input()
n_steps, m_records, min_v, max_v = line.split()
n_steps, m_records, min_v, max_v = int(n_steps), int(m_records), int(min_v), int(max_v)

line = input()

a = [int(i) for i in line.split()]

low = False

high = False

outbound = False

for i in a:
	if i == min_v:
		low = True 
	if i == max_v:
		high = True
	if i > max_v or i < min_v:
		outbound = True

sub = 2		
if high == True:
	sub = sub - 1
if low == True:
	sub = sub - 1

if n_steps - m_records - sub >= 0 and outbound == False:
	print("Correct")
else:
	print("Incorrect")

