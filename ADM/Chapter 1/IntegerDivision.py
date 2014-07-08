def divideBySub(a, b):
	'''Integer division without using / or *
		Simplest solution implemented below, which is to iteratively subtract the denominator from the numerator while the numerator is bigger than or equal to the denominator.'''
	count = 0
	while a >= b:
		count += 1
		a -= b
        
	return count

def divideBySubFaster(a, b):
	'''Makes division faster IF a/b yields no remainder, and a >> b.'''
	countB = 0
	lastB = b
	incrementedB = False
	while a % b == 0:
		incrementedB = True
		lastB = b
		b += b
		countB += 1

	if incrementedB:
		b -= lastB # revert last change
		countB -= 1 # revert last change

	result = divideBySub(a, b)
	for i in xrange(0, countB):
		result += result
    
	return result