%: usr/%.cpp
	g++ complex/complex.cpp ff/fourier.cpp usr/$@.cpp -o bin/$@
