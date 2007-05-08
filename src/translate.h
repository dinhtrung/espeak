/***************************************************************************
 *   Copyright (C) 2005,2006 by Jonathan Duddington                        *
 *   jonsd@users.sourceforge.net                                           *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

#define L(c1,c2)  (c1<<8)+c2          // combine two characters into an integer for translator name 

#define CTRL_EMBEDDED    0x01         // control character at the start of an embedded command
#define REPLACED_E       'E'          // 'e' replaced by silent e

#define N_WORD_PHONEMES  160          // max phonemes in a word
#define N_WORD_BYTES     160          // max bytes for the UTF8 characters in a word
#define N_CLAUSE_WORDS   256          // max words in a clause
#define N_RULE_GROUP2    120          // max num of two-letter rule chains
#define N_HASH_DICT     1024
#define N_CHARSETS        20

/* flags from word dictionary */
// bits 0-3  stressed syllable,  7=unstressed
#define FLAG_SKIPWORDS        0xe0  /* bits 5,6,7  number of words to skip */
#define FLAG_SKIPWORDS_1      0x20
#define FLAG_PREPAUSE        0x100
#define FLAG_ONLY            0x200
#define BITNUM_FLAG_ONLY         9  // bit 9 is set
#define BITNUM_FLAG_ONLY_S      10  // bit 10 is set
#define FLAG_ONLY_S          0x400
#define FLAG_STRESS_END      0x800  /* full stress if at end of clause */
#define FLAG_STRESS_END2    0x1000  /* full stress if at end of clause, or only followed by unstressed */
#define FLAG_UNSTRESS_END   0x2000  /* reduce stress at end of clause */
#define FLAG_ATEND          0x4000  /* use this pronunciation if at end of clause */

#define FLAG_CAPITAL        0x8000  /* pronunciation if initial letter is upper case */
#define FLAG_DOT           0x10000  /* ignore '.' after word (abbreviation) */
#define FLAG_ABBREV        0x20000  // spell as letters, even with a vowel, OR use specified pronunciation rather than split into letters
#define FLAG_STEM          0x40000  // must have a suffix

#define FLAG_DOUBLING      0x80000  // doubles the following consonant
#define FLAG_ALT_TRANS    0x100000  // language specific
#define FLAG_ALT2_TRANS   0x200000  // language specific

#define FLAG_VERBF        0x400000  /* verb follows */
#define FLAG_VERBSF       0x800000  /* verb follows, may have -s suffix */
#define FLAG_NOUNF       0x1000000  /* noun follows */
#define FLAG_VERB        0x2000000  /* pronunciation for verb */
#define FLAG_PAST        0x4000000  /* pronunciation for past tense */
#define FLAG_PASTF       0x8000000  /* past tense follows */
#define FLAG_VERB_EXT   0x10000000  /* extend the 'verb follows' */

#define FLAG_PAUSE1     0x40000000  // shorter prepause
#define FLAG_FOUND      0x80000000  /* pronunciation was found in the dictionary list */

// wordflags, flags in source word
#define FLAG_ALL_UPPER     0x1    /* no lower case letters in the word */
#define FLAG_FIRST_UPPER   0x2    /* first letter is upper case */
#define FLAG_HAS_PLURAL    0x4    /* upper-case word with s or 's lower-case ending */
#define FLAG_PHONEMES      0x8    /* word is phonemes */
#define FLAG_LAST_WORD     0x10   /* last word in clause */
#define FLAG_STRESSED_WORD 0x20   /* this word has explicit stress */
#define FLAG_EMBEDDED      0x40   /* word is preceded by embedded commands */
#define FLAG_HYPHEN        0x80
#define FLAG_DONT_SWITCH_TRANSLATOR  0x1000
#define FLAG_SUFFIX_REMOVED  0x2000
#define FLAG_HYPHEN_AFTER    0x4000

// prefix/suffix flags (bits 8 to 14, bits 16 to 22) don't use 0x8000, 0x800000
#define SUFX_E        0x0100   // e may have been added
#define SUFX_I        0x0200   // y may have been changed to i
#define SUFX_P        0x0400   // prefix
#define SUFX_V        0x0800   // suffix means use the verb form pronunciation
#define SUFX_D        0x1000   // previous letter may have been doubles
#define SUFX_F        0x2000   // verb follows
#define SUFX_Q        0x4000   // don't retranslate
#define SUFX_T        0x10000   // don't affect the stress position in the stem

#define FLAG_SUFX       0x04
#define FLAG_SUFX_S     0x08
#define FLAG_SUFX_E_ADDED 0x10


// codes in dictionary rules
#define RULE_PRE			1
#define RULE_POST			2
#define RULE_PHONEMES	3
#define RULE_PH_COMMON	4	// At start of rule. Its phoneme string is used by subsequent rules
#define RULE_CONDITION	5	// followed by condition number (byte)
#define RULE_GROUP_START 6
#define RULE_GROUP_END	7

#define RULE_SPACE		32   // ascii space
#define RULE_SYLLABLE	9
#define RULE_STRESSED	10
#define RULE_DOUBLE		11
#define RULE_INC_SCORE	12
#define RULE_DEL_FWD		13
#define RULE_ENDING		14
#define RULE_DIGIT		15   // D digit
#define RULE_NONALPHA	16   // Z non-alpha
#define RULE_LETTER_GROUPS 17  // 17 to 23
#define RULE_LETTER1		17   // A vowels
#define RULE_LETTER2		18   // B 'hard' consonants 
#define RULE_LETTER3		19   // C all consonants
#define RULE_LETTER4		20   // H letter group
#define RULE_LETTER5    21   // F letter group
#define RULE_LETTER6		22   // G letter group
#define RULE_LETTER7    23   // Y letter group
#define RULE_NO_SUFFIX  24   // N
#define RULE_NOTVOWEL   25   // K
#define RULE_IFVERB     26   // V
#define RULE_LETTERGP   27   // L + letter group number
#define RULE_ALT1       28   // word has $alt attribute
#define RULE_LAST_RULE   28

#define LETTERGP_A	0
#define LETTERGP_B	1
#define LETTERGP_C	2
#define LETTERGP_H	3
#define LETTERGP_F	4
#define LETTERGP_G	5
#define LETTERGP_Y	6
#define LETTERGP_VOWEL2   7


// Punctuation types  returned by ReadClause()
// bits 0-7 pause x 10mS, bits 8-10 intonation type,
// bit 15=sentence, bit 14=clause,  bits 13=voice change
// bit 12 used to distinguish otherwise identical types
#define CLAUSE_BIT_SENTENCE  0x8000
#define CLAUSE_BIT_VOICE     0x2000

#define CLAUSE_NONE         0 + 0x0400
#define CLAUSE_PARAGRAPH   70 + 0x8000
#define CLAUSE_EOF         35 + 0x9000
#define CLAUSE_VOICE        0 + 0x2400
#define CLAUSE_PERIOD      35 + 0x8000
#define CLAUSE_COMMA       20 + 0x4100
#define CLAUSE_SHORTCOMMA  15 + 0x4100
#define CLAUSE_QUESTION    35 + 0x8200
#define CLAUSE_EXCLAMATION 40 + 0x8300
#define CLAUSE_COLON       30 + 0x4000
#ifdef PLATFORM_RISCOS
#define CLAUSE_SEMICOLON   30 + 0x4000
#else
#define CLAUSE_SEMICOLON   30 + 0x4100
#endif

#define SAYAS_CHARS     0x12
#define SAYAS_GLYPHS    0x13
#define SAYAS_SINGLE_CHARS 0x14
#define SAYAS_KEY       0x20
#define SAYAS_DIGITS1   0x21
#define SAYAS_DIGITS    0x30  // + number of digits

// Rule:
// [4] [match] [1 pre] [2 post] [3 phonemes] 0
//     match 1 pre 2 post 0     - use common phoneme string
//     match 1 pre 2 post 3 0   - empty phoneme string


typedef struct {
	int points;
	const char *phonemes;
	int end_type;
	char *del_fwd;
} MatchRecord;
	

// used to mark words with the source[] buffer
typedef struct{
	unsigned short start;
	unsigned short sourceix;
	unsigned short flags;
	unsigned char pre_pause;
	unsigned char wmark;
	unsigned char length;
} WORD_TAB;

// a clause translated into phoneme codes (first stage)
typedef struct {
	unsigned char phcode;
	unsigned char stress;
	unsigned char tone_number; 
	unsigned char synthflags;
	unsigned short sourceix;
} PHONEME_LIST2;


typedef struct {
	int type;
	int parameter[N_SPEECH_PARAM];
} PARAM_STACK;

extern PARAM_STACK param_stack[];
extern const int param_defaults[N_SPEECH_PARAM];



#define N_LOPTS      12
#define LOPT_DIERESES        1
 // 1=remove [:] from unstressed syllables, 2= remove from unstressed or non-penultimate syllables
#define LOPT_IT_LENGTHEN        2
 // 1=german
#define LOPT_PREFIXES        3
 // non-zero, change voiced/unoiced to match last consonant in a cluster
 // bit 1=LANG=ru,  don't propagate over [v]
 // bit 2=don't propagate acress word boundaries
 // bit 3=LANG=pl,  propagate over liquids and nasals
#define LOPT_REGRESSIVE_VOICING  4
 // 0=default, 1=no check, other allow this character as an extra initial letter (default is 's')
#define LOPT_UNPRONOUNCABLE  5
 // select length_mods tables,  (length_mod_tab) + (length_mod_tab0 * 100)
#define LOPT_LENGTH_MODS    6
 // increase this to prevent sonorants being shortened before shortened (eg. unstressed) vowels
#define LOPT_SONORANT_MIN    7
 // Italian "syntactic doubling"
#define LOPT_IT_DOUBLING     8
 // max. amplitude for vowel at the end of a clause
#define LOPT_MAXAMP_EOC      9
 // don't reduce the strongest vowel in a word which is marked 'unstressed'
#define LOPT_KEEP_UNSTR_VOWEL  10
 // LANG=cs,sk  combine some prepositions with the following word, if the combination has N or fewer syllables
#define LOPT_COMBINE_WORDS 11


typedef struct {
// bit0=don't link consonants with the next word
// bit1=don't add linking phonemes
// bit2=length of a final vowel doesn't depend on the next phoneme
// bit4=longer pause before STOP, VSTOP,FRIC
// bit8-11=separate words with adjacent stressed syllables with (1=pause, 2=long pausem 3=[?] phoneme)
	int word_gap;
	int vowel_pause;
	int stress_rule; // 1=first syllable, 2=penultimate,  3=last

// bit0=don't stress monosyllables,
// bit1=don't set diminished stress,
// bit2=mark unstressed final syllables as diminished
// bit4=don't allow secondary stress on last syllable
// bit5-don't use automatic secondary stress
// bit6=light syllable followed by heavy, move secondary stress to the heavy syllable. LANG=Finnish
// bit8=stress last syllable if it doesn't end in a vowel
// bit9=stress last syllable if it doesn't end in vowel or "s" or "n"  LANG=Spanish
// bit12= If there is only one syllable before the primary stress, give it a secondary stress

	int stress_flags; 
	int unstressed_wd1; // stress for $u word of 1 syllable
	int unstressed_wd2; // stress for $u word of >1 syllable
	int param[N_LOPTS];
	unsigned char *length_mods;
	unsigned char *length_mods0;

	// bits0-1=which numbers routine to use.
	// bit2=  thousands separator must be space
	// bit3=  , decimal separator, not .
	// bit4=use three-and-twenty rather than twenty-three
	// bit5='and' between tens and units
	// bit6=add "and" after hundred and thousand
	// bit7=don't have "and" both after hundreds and also between tens and units
   // bit8=only one primary stress in tens+units
	// bit9=only one vowel betwen tens and units
	// bit10=omit "one" before "hundred"
	// bit11=don't say 19** as nineteen hundred
	// bit12=allow space as thousands separator (in addition to langopts.thousands_sep)
	// bits13-15  post-decimal-digits 0=single digits, 1=(LANG=it) 2=(LANG=pl) 3=(LANG=ro)
	// bit16=dot after number indicates ordinal
	// bit18=special word for 100,000s LANG=sw
	// bit19=(LANG=pl)

	int numbers;

	// bits 1-4  use variant form of numbers before thousands,millions,etc.
	int numbers2;

	int thousands_sep;
	int decimal_sep;
	int intonation;          // 1=tone language
	int long_stop;          // extra mS pause for a lengthened stop
	int phoneme_change;     // TEST, change phonemes, after translation
	char max_initial_consonants;
	char spelling_stress;   // 0=default, 1=stress first letter
	char tone_numbers;
	char ideographs;      // treat as separate words
	int testing;            // testing options: bit 1= specify stressed syllable in the form:  "outdoor/2"
	const wchar_t *replace_chars;   // characters to be substitutes
	const wchar_t *replacement_chars;  // substitutes for replace_chars
} LANGUAGE_OPTIONS;


// a parameter of ChangePhonemes()
typedef struct {
	int flags;
	unsigned char stress;          // stress level of this vowel
	unsigned char stress_highest;  // the highest stress level of a vowel in this word
	unsigned char n_vowels;        // number of vowels in the word
	unsigned char vowel_this;      // syllable number of this vowel (counting from 1)
	unsigned char vowel_stressed;  // syllable number of the highest stressed vowel
} CHANGEPH;



#define NUM_SEP_DOT    0x0008    // . , for thousands and decimal separator
#define NUM_SEP_SPACE  0x1000    // allow space as thousands separator (in addition to langopts.thousands_sep)
#define NUM_DEC_IT     0x2000    // (LANG=it) speak post-decimal-point digits as a combined number not as single digits

class Translator
{//=============
public:
	Translator();
	virtual ~Translator();
	void *TranslateClause(FILE *f_text, const void *vp_input, int *tone, char **voice_change);
	int TranslateWord(char *word, int next_pause, WORD_TAB *wtab);
	int LoadDictionary(const char *name, int no_error);
	virtual void CalcLengths();
	virtual void CalcPitches(int clause_tone);
	
	LANGUAGE_OPTIONS langopts;
	int translator_name;
	int transpose_offset;
	int transpose_max;
	int transpose_min;

	char phon_out[300];
	char word_phonemes[N_WORD_PHONEMES];    // a word translated into phoneme codes

	int stress_amps[8];
	int stress_amps_r[8];
	int stress_lengths[8];
	int dict_condition;    // conditional apply some pronunciation rules and dict.lookups
	const unsigned short *charset_a0;   // unicodes for characters 0xa0 to oxff
	const wchar_t *char_plus_apostrophe;  // single chars + apostrophe treated as words

// holds properties of characters: vowel, consonant, etc for pronunciation rules
	unsigned char letter_bits[256];
	int letter_bits_offset;
#define N_LETTER_TYPES 20
	const wchar_t *letter_groups[N_LETTER_TYPES];

	/* index1=option, index2 by 0=. 1=, 2=?, 3=! 4=none */
	unsigned char punct_to_tone[4][5];

	char *data_dictrules;     // language_1   translation rules file
	char *data_dictlist;      // language_2   dictionary lookup file
	char *dict_hashtab[N_HASH_DICT];   // hash table to index dictionary lookup file


private:
	int TranslateWord2(char *word, WORD_TAB *wtab, int pre_pause, int next_pause);
	int TranslateLetter(char *letter, char *phonemes, int control);
	void SetSpellingStress(char *phonemes, int control);
	void GetTranslatedPhonemeString(char *phon_out, int n_phon_out);
	void WriteMnemonic(int *ix, int mnem);
	void MakePhonemeList(int post_pause, int new_sentence);
	int SubstitutePhonemes(PHONEME_LIST2 *plist_out);

	int ReadClause(FILE *f_in, char *buf, unsigned short *charix, int n_buf);
	int AnnouncePunctuation(int c1, int c2, char *buf, int ix);

	int LookupDict2(char *word, char *word2, char *phonetic, unsigned int *flags, int end_flags);
	const char *LookupSpecial(char *string);
	const char *LookupCharName(int c);
	int LookupNum2(int value, int control, char *ph_out);
	int LookupNum3(int value, char *ph_out, int suppress_null, int thousandplex, int prev_thousands);
	int LookupThousands(int value, int thousandplex, char *ph_out);
   int TranslateNumber_1(char *word1, char *ph_out, unsigned int *flags, int wflags);

	void InitGroups(void);
	void AppendPhonemes(char *string, int size, const char *ph);
	char *DecodeRule(const char *group, char *rule);
	void MatchRule(char *word[], const char *group, char *rule, MatchRecord *match_out, int end_flags, int dict_flags);
	int TranslateRules(char *p, char *phonemes, int size, char *end_phonemes, int end_flags, int dict_flags);
	void ApplySpecialAttribute(char *phonemes, int dict_flags);

	int IsLetter(int letter, int group);

	void CalcPitches_Tone(int clause_tone);

protected:
	virtual int Unpronouncable(char *word);
	virtual void SetWordStress(char *output, unsigned int dictionary_flags, int tonic, int prev_stress);
	virtual int RemoveEnding(char *word, int end_type, char *word_copy);
	virtual int TranslateChar(char *ptr, int prev_in, int c, int next_in);
   virtual int TranslateNumber(char *word1, char *ph_out, unsigned int *flags, int wflags);
	virtual int ChangePhonemes(PHONEME_LIST2 *phlist, int n_ph, int index, PHONEME_TAB *ph, CHANGEPH *ch);

	int IsVowel(int letter);
	int LookupDictList(char *word1, char *ph_out, unsigned int *flags, int end_flags);
	int Lookup(char *word, char *ph_out);

	
	// groups1 and groups2 are indexes into data_dictrules, set up by InitGroups()
	// the two-letter rules for each letter must be consecutive in the language_rules source
	
	char *groups1[256];         // translation rule lists, index by single letter
	char *groups2[N_RULE_GROUP2];   // translation rule lists, indexed by two-letter pairs
	unsigned int groups2_name[N_RULE_GROUP2];  // the two letter pairs for groups2[]
	int n_groups2;              // number of groups2[] entries used
	
	unsigned char groups2_count[256];    // number of 2 letter groups for this initial letter
	unsigned char groups2_start[256];    // index into groups2
	
	int n_ph_list2;
	PHONEME_LIST2 ph_list2[N_PHONEME_LIST];	// first stage of text->phonemes

	

	int expect_verb;
	int expect_past;    // expect past tense
	int expect_verb_s;
	int word_flags;     // word is all upper case
	int prev_last_stress;
	int prepause_timeout;
	int end_stressed_vowel;  // word ends with stressed vowel
	int prev_dict_flags;     // dictionary flags from previous word
	char *clause_end;

	int word_vowel_count;     // number of vowels so far
	int word_stressed_count;  // number of vowels so far which could be stressed
	
	int clause_upper_count;   // number of upper case letters in the clause
	int clause_lower_count;   // number of lower case letters in the clause

}; //  end of class Translator


extern int option_tone1;
extern int option_tone2;
extern int option_waveout;
extern int option_quiet;
extern int option_phonemes;
extern int option_linelength;     // treat lines shorter than this as end-of-clause
extern int option_harmonic1;
extern int option_multibyte;
extern int option_capitals;
extern int option_punctuation;
extern int option_endpause;
extern int option_ssml;
extern int option_phoneme_input;   // allow [[phonemes]] in input text
extern int option_phoneme_variants;
extern int option_sayas;

extern int count_characters;
extern int count_words;
extern int count_sentences;
extern int skip_characters;
extern int skip_words;
extern int skip_sentences;
extern int skipping_text;
extern int end_character_position;
extern int clause_start_char;
extern int clause_start_word;
extern char *namedata;



#define N_MARKER_LENGTH 50   // max.length of a mark name
extern char skip_marker[N_MARKER_LENGTH];

#define N_PUNCTLIST  60
extern wchar_t option_punctlist[N_PUNCTLIST];

extern int speech_parameters[];

extern Translator *translator;
extern const unsigned short *charsets[N_CHARSETS];
extern char dictionary_name[40];
extern char ctrl_embedded;    // to allow an alternative CTRL for embedded commands
extern char *p_textinput;
extern wchar_t *p_wchar_input;
extern int ungot_char;
extern int (* uri_callback)(int, const char *, const char *);
extern void SetLengthMods(Translator *tr, int value);

Translator *SelectTranslator(const char *name);
int CompileDictionary(const char *dsource, const char *dict_name, FILE *log, char *err_name);
void LoadConfig(void);
int PhonemeCode(unsigned int mnem);
void ChangeWordStress(char *word, int new_stress);
int TransposeAlphabet(char *text, int offset, int min, int max);
int utf8_in(int *c, char *buf, int backwards);
int utf8_out(unsigned int c, char *buf);
int lookupwchar(const unsigned short *list,int c);
int Eof(void);
char *strchr_w(const char *s, int c);
int IsBracket(int c);
void SetLetterBits(Translator *tr, int group, const char *string);
void SetLetterBitsRange(Translator *tr, int group, int first, int last);
void SetLetterVowel(Translator *tr, int c);
void InitNamedata(void);
void InitText(int flags);
void InitText2(void);
int IsDigit(unsigned int c);
int IsAlpha(unsigned int c);
int isspace2(unsigned int c);

extern FILE *f_trans;		// for logging