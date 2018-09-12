x = input()
ans = 0
quater = 0
dimes = 0
nickle = 0
pennies = 0

while(x>0):
	if(x >= 25 ):
		x -= 25
		quater += 1
		ans +=1
	elif(x >= 10):	
		x -= 10
		dimes += 1
		ans += 1
	elif(x >= 5):
		x -= 5
		nickle += 1 
		ans += 1
	else:
		pennies += x
		ans +=x
		x = 0


print 'total coin ', ans
print 'quater :', quater
print 'dimes  :', dimes
print 'nickle :', nickle
print 'pennies:', pennies