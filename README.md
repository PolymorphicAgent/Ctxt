# Ctxt (Colored Text) C++ Command Line Library

A very simple library that manages color escape sequences for c++ terminal applications. This includes bold, underline, colors, etc.

Usage
```
// This is the function signiture
ctxt(std::string s, const int textcolor, bool bold, bool underline, bool newline);

// You may use the following defined colors for <textcolor>
black      
dark_blue  
dark_green 
light_blue 
dark_red   
magenta    
orange     
light_gray 
gray       
blue       
green     
cyan      
red       
pink      
yellow    
white

// Example Usage
ctxt("Hello World!", green, true, true, true);  // Outputs text that says "Hello World!" colored green, bold, underlined, and a newline at the end!

```
