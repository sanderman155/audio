# audio save

This program saves sections of volume with the initially set parameter as separate audio files.

## GETTING STARTED 

  1. **Compile library by using makefile**
  ```
  make vad
  ```
  2. **Change your directory**  
  ```
  cd audio/
  ```
  3. **Execute the program**
  ```
  bin/vad example.wav 0.1 0.01
  ```
 
# Fast and sicrete fourier transform
	
The Fourier Transform is a tool that breaks a waveform (a function or signal) into an alternate representation, characterized by sine and cosines. The Fourier Transform shows that any waveform can be re-written as the sum of sinusoidal functions. 

A fast Fourier transform is an algorithm that computes the discrete Fourier transform of a sequence, or its inverse. Fourier analysis converts a signal from its original domain (often time or space) to a representation in the frequency domain and vice versa.

## GETTING STARTED 
   
  1. **Compile library by using makefile**
  ```
  make main
  ```
  2. **Change your directory**  
  ```
  cd audio/
  ```
  3. **Execute the program**
  ```
  bin/main
  ```
