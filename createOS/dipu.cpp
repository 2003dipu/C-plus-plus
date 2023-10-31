extern "C" void kernel_main()
{
    // Simple kernel that prints "Hello, World!" to the screen
    const char* hello = "Hello, World!";
    volatile unsigned char* video_memory = (volatile unsigned char*)0xB8000;
    
    for (int i = 0; hello[i] != '\0'; ++i) {
        video_memory[i * 2] = hello[i];
        video_memory[i * 2 + 1] = 0x0F; // Text color: white on black
    }
    
    while (1) {
        // Loop indefinitely
    }
}
