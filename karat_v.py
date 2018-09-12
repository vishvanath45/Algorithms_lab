import math

def karatsuba(a,b):

	if(a<10 or b < 10):
			return (int(a*b))
	kk = int(math.log(a)/math.log(10))

	x2 = a%(10**kk)
	x1 = a - x2
	x1 = a/(10**kk)
	y2 = b%(10**kk)
	y1 = b - y2
	y1 = b/(10**kk) 

	# else when a>=10 and b >=10
	
	a = karatsuba(x1,y1)
	c = karatsuba(x2,y2)
	pp = x1+x2
	qq = y1+y2
	b = karatsuba(pp,qq) - a - c 
	return (a*(10**(2*kk)) + b*(10**kk) + c)

a = int(input())
b = int(input())
print "the ans is " , karatsuba(a,b)		

# 229 = 2 * 100 + 29 


