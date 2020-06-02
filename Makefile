%: usr/%.cpp
	g++ complex/complex.cpp ff/fourier.cpp usr/$@.cpp -o bin/$@
vad: save/vad.cpp
	g++ save/vad.cpp -o bin/vad
