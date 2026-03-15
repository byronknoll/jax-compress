
#define COMP_INTRO_END_LINE 29
#define COMP_MAIN_END_LINE  13146932
#define COMP_CODA_END_LINE  13147025

void wfputs(const char *str,FILE *fp) {
    for (; *str; str++){
        putc(*str,fp);
    }
}

int wfgets(char *str, int count, FILE  *fp) {
    int c, i = 0;
    while (i<count-1 && ((c=getc(fp))!=EOF)) {
        str[i++]=c;
        if (c=='\n')
            break;
    }
    str[i]=0;
    return i;
}

bool cat(char const * filename_from1, char const * filename_from2, char const * filename_to) {
  FILE* ifile1 = fopen(filename_from1, "rb");
  FILE* ifile2 = fopen(filename_from2, "rb");
  FILE* ofile = fopen(filename_to, "wb");
  
  do {
    int c=getc(ifile1);
    if (c==EOF) break;
    putc(c,ofile);
  }
  while (!feof(ifile1));
  do {
    int c=getc(ifile2);
    if (c==EOF) break;
    putc(c,ofile);
  }
  while (!feof(ifile2));
  fclose(ifile1);
  fclose(ifile2);
  fclose(ofile);

  return true;
}

void split4Comp(char const *enwik9_filename) {
  FILE* ifile = fopen(enwik9_filename, "rb");
  FILE* ofile1 = fopen(".intro", "wb");
  FILE* ofile2 = fopen(".main", "wb");
  FILE* ofile3 = fopen(".coda", "wb");  
  int line_count = 0;
  
  do {
    int c=getc(ifile);
    if (c==EOF) break;
    if (line_count < COMP_INTRO_END_LINE) {
      putc(c,ofile1);
    } else if (line_count < COMP_MAIN_END_LINE) {
      putc(c,ofile2);
    } else if (line_count < COMP_CODA_END_LINE) {
      putc(c,ofile3);
    } else {
      putc(c,ofile3);
    }
    if (c==10)
    line_count++;
  }
  while (!feof(ifile));
  fclose(ifile);
  fclose(ofile1);
  fclose(ofile2);
  fclose(ofile3);
}

void split4Decomp( const char* inpnam ) {
  FILE* ifile = fopen(inpnam, "rb");
  FILE* ofile1 = fopen(".intro_decomp", "wb");
  FILE* ofile2 = fopen(".main_decomp", "wb");
  FILE* ofile3 = fopen(".coda_decomp", "wb");  
  int byte_count = 0;
  
  do {
      int c=getc(ifile);
      if (c==EOF) break;
    if (byte_count < 999988851) {
      putc(c,ofile2);
    } else if (byte_count < 999990255) {
        putc(c,ofile1);
    } else {
        putc(c,ofile3);
    }
    ++byte_count;
  }
  while (!feof(ifile));
  fclose(ifile);
  fclose(ofile1);
  fclose(ofile2);
  fclose(ofile3);
  
}
