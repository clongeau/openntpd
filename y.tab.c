#ifndef lint
static const char yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93";
#endif

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20120115

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)

#define YYPREFIX "yy"

#define YYPURE 0

#line 23 "./parse.y"
#include "includes.h"

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include <ctype.h>
#include <errno.h>
#include <limits.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <syslog.h>

#include "ntpd.h"

TAILQ_HEAD(files, file)		 files = TAILQ_HEAD_INITIALIZER(files);
static struct file {
	TAILQ_ENTRY(file)	 entry;
	FILE			*stream;
	char			*name;
	int			 lineno;
	int			 errors;
} *file, *topfile;
struct file	*pushfile(const char *);
int		 popfile(void);
int		 yyparse(void);
int		 yylex(void);
int		 yyerror(const char *, ...);
int		 kw_cmp(const void *, const void *);
int		 lookup(char *);
int		 lgetc(int);
int		 lungetc(int);
int		 findeol(void);

struct ntpd_conf		*conf;

struct opts {
	int		weight;
	int		correction;
	int		rtable;
	char		*refstr;
} opts;
void		opts_default(void);

typedef struct {
	union {
		int64_t			 number;
		char			*string;
		struct ntp_addr_wrap	*addr;
		struct opts		 opts;
	} v;
	int lineno;
} YYSTYPE;

#line 77 "y.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define LISTEN 257
#define ON 258
#define SERVER 259
#define SERVERS 260
#define SENSOR 261
#define CORRECTION 262
#define RTABLE 263
#define REFID 264
#define WEIGHT 265
#define ERROR 266
#define STRING 267
#define NUMBER 268
#define YYERRCODE 256
static const short yylhs[] = {                           -1,
    0,    0,    0,    0,   15,   15,   15,   15,    1,   16,
    2,    2,    3,    3,    4,   17,    5,    5,    6,    6,
    7,    7,   18,    8,    8,    9,    9,   10,   10,   10,
   11,   13,   14,   12,
};
static const short yylen[] = {                            2,
    0,    2,    3,    3,    4,    3,    3,    3,    1,    0,
    2,    0,    2,    1,    1,    0,    2,    0,    2,    1,
    1,    1,    0,    2,    0,    2,    1,    1,    1,    1,
    2,    2,    2,    2,
};
static const short yydefred[] = {                         1,
    0,    0,    0,    0,    0,    0,    2,    0,    4,    0,
    9,    0,    0,    0,    3,    0,    7,    0,    6,    8,
    0,    5,    0,    0,    0,    0,   20,   22,   21,    0,
    0,    0,   27,   28,   29,   30,    0,   14,   15,   34,
   33,   19,   31,   32,   26,   13,
};
static const short yydgoto[] = {                          1,
   12,   22,   37,   38,   17,   26,   27,   20,   32,   33,
   34,   28,   35,   29,    8,   23,   18,   21,
};
static const short yysindex[] = {                         0,
    3,    1, -244, -250, -250, -249,    0,    9,    0, -250,
    0,    0,    0,    0,    0,    0,    0, -253,    0,    0,
 -256,    0, -243, -247, -246, -253,    0,    0,    0, -245,
 -242, -256,    0,    0,    0,    0, -243,    0,    0,    0,
    0,    0,    0,    0,    0,    0,
};
static const short yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   -7,   -7,  -10,    0,   -6,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   14,    0,    0,    0,    0,
    0,   16,    0,    0,    0,    0,   17,    0,    0,    0,
    0,    0,    0,    0,    0,    0,
};
static const short yygindex[] = {                         0,
   -3,    0,    0,   -9,   18,    0,    4,    0,    0,    2,
    0,  -22,    0,  -16,    0,    0,    0,    0,
};
#define YYTABLESIZE 264
static const short yytable[] = {                         25,
   39,   13,   18,   12,   36,   30,   16,   31,   25,   24,
    9,   25,    7,   10,   39,   36,   11,   14,   15,   24,
   40,   41,   43,   17,   44,   24,   11,   46,    0,   42,
   19,    0,    0,   45,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   23,    0,   23,   23,   16,   10,   16,    2,    3,
    0,    4,    5,    6,
};
static const short yycheck[] = {                         10,
   23,    5,   10,   10,   21,  262,   10,  264,  265,  263,
   10,  265,   10,  258,   37,   32,  267,  267,   10,  263,
  268,  268,  268,   10,  267,   10,   10,   37,   -1,   26,
   13,   -1,   -1,   32,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  262,   -1,  264,  265,  263,  263,  265,  256,  257,
   -1,  259,  260,  261,
};
#define YYFINAL 1
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 268
#if YYDEBUG
static const char *yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,"'\\n'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"LISTEN","ON","SERVER",
"SERVERS","SENSOR","CORRECTION","RTABLE","REFID","WEIGHT","ERROR","STRING",
"NUMBER",
};
static const char *yyrule[] = {
"$accept : grammar",
"grammar :",
"grammar : grammar '\\n'",
"grammar : grammar main '\\n'",
"grammar : grammar error '\\n'",
"main : LISTEN ON address listen_opts",
"main : SERVERS address server_opts",
"main : SERVER address server_opts",
"main : SENSOR STRING sensor_opts",
"address : STRING",
"$$1 :",
"listen_opts : $$1 listen_opts_l",
"listen_opts :",
"listen_opts_l : listen_opts_l listen_opt",
"listen_opts_l : listen_opt",
"listen_opt : rtable",
"$$2 :",
"server_opts : $$2 server_opts_l",
"server_opts :",
"server_opts_l : server_opts_l server_opt",
"server_opts_l : server_opt",
"server_opt : weight",
"server_opt : rtable",
"$$3 :",
"sensor_opts : $$3 sensor_opts_l",
"sensor_opts :",
"sensor_opts_l : sensor_opts_l sensor_opt",
"sensor_opts_l : sensor_opt",
"sensor_opt : correction",
"sensor_opt : refid",
"sensor_opt : weight",
"correction : CORRECTION NUMBER",
"refid : REFID STRING",
"weight : WEIGHT NUMBER",
"rtable : RTABLE NUMBER",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 500
#define YYMAXDEPTH  500
#endif
#endif

#define YYINITSTACKSIZE 500

typedef struct {
    unsigned stacksize;
    short    *s_base;
    short    *s_mark;
    short    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 313 "./parse.y"

void
opts_default(void)
{
	bzero(&opts, sizeof opts);
	opts.weight = 1;
	opts.rtable = -1;
}

struct keywords {
	const char	*k_name;
	int		 k_val;
};

int
yyerror(const char *fmt, ...)
{
	va_list		 ap;
	char		*nfmt;

	file->errors++;
	va_start(ap, fmt);
	if (asprintf(&nfmt, "%s:%d: %s", file->name, yylval.lineno, fmt) == -1)
		fatalx("yyerror asprintf");
	vlog(LOG_CRIT, nfmt, ap);
	va_end(ap);
	free(nfmt);
	return (0);
}

int
kw_cmp(const void *k, const void *e)
{
	return (strcmp(k, ((const struct keywords *)e)->k_name));
}

int
lookup(char *s)
{
	/* this has to be sorted always */
	static const struct keywords keywords[] = {
		{ "correction",		CORRECTION},
		{ "listen",		LISTEN},
		{ "on",			ON},
		{ "refid",		REFID},
		{ "rtable",		RTABLE},
		{ "sensor",		SENSOR},
		{ "server",		SERVER},
		{ "servers",		SERVERS},
		{ "weight",		WEIGHT}
	};
	const struct keywords	*p;

	p = bsearch(s, keywords, sizeof(keywords)/sizeof(keywords[0]),
	    sizeof(keywords[0]), kw_cmp);

	if (p)
		return (p->k_val);
	else
		return (STRING);
}

#define MAXPUSHBACK	128

char	*parsebuf;
int	 parseindex;
char	 pushback_buffer[MAXPUSHBACK];
int	 pushback_index = 0;

int
lgetc(int quotec)
{
	int		c, next;

	if (parsebuf) {
		/* Read character from the parsebuffer instead of input. */
		if (parseindex >= 0) {
			c = parsebuf[parseindex++];
			if (c != '\0')
				return (c);
			parsebuf = NULL;
		} else
			parseindex++;
	}

	if (pushback_index)
		return (pushback_buffer[--pushback_index]);

	if (quotec) {
		if ((c = getc(file->stream)) == EOF) {
			yyerror("reached end of file while parsing "
			    "quoted string");
			if (file == topfile || popfile() == EOF)
				return (EOF);
			return (quotec);
		}
		return (c);
	}

	while ((c = getc(file->stream)) == '\\') {
		next = getc(file->stream);
		if (next != '\n') {
			c = next;
			break;
		}
		yylval.lineno = file->lineno;
		file->lineno++;
	}

	while (c == EOF) {
		if (file == topfile || popfile() == EOF)
			return (EOF);
		c = getc(file->stream);
	}
	return (c);
}

int
lungetc(int c)
{
	if (c == EOF)
		return (EOF);
	if (parsebuf) {
		parseindex--;
		if (parseindex >= 0)
			return (c);
	}
	if (pushback_index < MAXPUSHBACK-1)
		return (pushback_buffer[pushback_index++] = c);
	else
		return (EOF);
}

int
findeol(void)
{
	int	c;

	parsebuf = NULL;

	/* skip to either EOF or the first real EOL */
	while (1) {
		if (pushback_index)
			c = pushback_buffer[--pushback_index];
		else
			c = lgetc(0);
		if (c == '\n') {
			file->lineno++;
			break;
		}
		if (c == EOF)
			break;
	}
	return (ERROR);
}

int
yylex(void)
{
	char	 buf[8096];
	char	*p;
	int	 quotec, next, c;
	int	 token;

	p = buf;
	while ((c = lgetc(0)) == ' ' || c == '\t')
		; /* nothing */

	yylval.lineno = file->lineno;
	if (c == '#')
		while ((c = lgetc(0)) != '\n' && c != EOF)
			; /* nothing */

	switch (c) {
	case '\'':
	case '"':
		quotec = c;
		while (1) {
			if ((c = lgetc(quotec)) == EOF)
				return (0);
			if (c == '\n') {
				file->lineno++;
				continue;
			} else if (c == '\\') {
				if ((next = lgetc(quotec)) == EOF)
					return (0);
				if (next == quotec || c == ' ' || c == '\t')
					c = next;
				else if (next == '\n') {
					file->lineno++;
					continue;
				} else
					lungetc(next);
			} else if (c == quotec) {
				*p = '\0';
				break;
			}
			if (p + 1 >= buf + sizeof(buf) - 1) {
				yyerror("string too long");
				return (findeol());
			}
			*p++ = (char)c;
		}
		yylval.v.string = strdup(buf);
		if (yylval.v.string == NULL)
			fatal("yylex: strdup");
		return (STRING);
	}

#define allowed_to_end_number(x) \
	(isspace(x) || x == ')' || x ==',' || x == '/' || x == '}' || x == '=')

	if (c == '-' || isdigit(c)) {
		do {
			*p++ = c;
			if ((unsigned)(p-buf) >= sizeof(buf)) {
				yyerror("string too long");
				return (findeol());
			}
		} while ((c = lgetc(0)) != EOF && isdigit(c));
		lungetc(c);
		if (p == buf + 1 && buf[0] == '-')
			goto nodigits;
		if (c == EOF || allowed_to_end_number(c)) {
			const char *errstr = NULL;

			*p = '\0';
			yylval.v.number = strtonum(buf, LLONG_MIN,
			    LLONG_MAX, &errstr);
			if (errstr) {
				yyerror("\"%s\" invalid number: %s",
				    buf, errstr);
				return (findeol());
			}
			return (NUMBER);
		} else {
nodigits:
			while (p > buf + 1)
				lungetc(*--p);
			c = *--p;
			if (c == '-')
				return (c);
		}
	}

#define allowed_in_string(x) \
	(isalnum(x) || (ispunct(x) && x != '(' && x != ')' && \
	x != '{' && x != '}' && x != '<' && x != '>' && \
	x != '!' && x != '=' && x != '/' && x != '#' && \
	x != ','))

	if (isalnum(c) || c == ':' || c == '_' || c == '*') {
		do {
			*p++ = c;
			if ((unsigned)(p-buf) >= sizeof(buf)) {
				yyerror("string too long");
				return (findeol());
			}
		} while ((c = lgetc(0)) != EOF && (allowed_in_string(c)));
		lungetc(c);
		*p = '\0';
		if ((token = lookup(buf)) == STRING)
			if ((yylval.v.string = strdup(buf)) == NULL)
				fatal("yylex: strdup");
		return (token);
	}
	if (c == '\n') {
		yylval.lineno = file->lineno;
		file->lineno++;
	}
	if (c == EOF)
		return (0);
	return (c);
}

struct file *
pushfile(const char *name)
{
	struct file	*nfile;

	if ((nfile = calloc(1, sizeof(struct file))) == NULL) {
		log_warn("malloc");
		return (NULL);
	}
	if ((nfile->name = strdup(name)) == NULL) {
		log_warn("malloc");
		free(nfile);
		return (NULL);
	}
	if ((nfile->stream = fopen(nfile->name, "r")) == NULL) {
		log_warn("%s", nfile->name);
		free(nfile->name);
		free(nfile);
		return (NULL);
	}
	nfile->lineno = 1;
	TAILQ_INSERT_TAIL(&files, nfile, entry);
	return (nfile);
}

int
popfile(void)
{
	struct file	*prev;

	if ((prev = TAILQ_PREV(file, files, entry)) != NULL)
		prev->errors += file->errors;

	TAILQ_REMOVE(&files, file, entry);
	fclose(file->stream);
	free(file->name);
	free(file);
	file = prev;
	return (file ? 0 : EOF);
}

int
parse_config(const char *filename, struct ntpd_conf *xconf)
{
	int		 errors = 0;

	conf = xconf;
	TAILQ_INIT(&conf->listen_addrs);
	TAILQ_INIT(&conf->ntp_peers);
	TAILQ_INIT(&conf->ntp_conf_sensors);

	if ((file = pushfile(filename)) == NULL) {
		return (-1);
	}
	topfile = file;

	yyparse();
	errors = file->errors;
	popfile();

	return (errors ? -1 : 0);
}
#line 652 "y.tab.c"

#if YYDEBUG
#include <stdio.h>		/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    short *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return -1;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = data->s_mark - data->s_base;
    newss = (short *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return -1;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return -1;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack)) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEX) < 0) yychar = 0;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    yyerror("syntax error");

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yystack.s_mark]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == 0) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 4:
#line 100 "./parse.y"
	{ file->errors++; }
break;
case 5:
#line 103 "./parse.y"
	{
			struct listen_addr	*la;
			struct ntp_addr		*h, *next;

			if (yystack.l_mark[-1].v.addr->a)
				yystack.l_mark[-1].v.addr->a->rtable = yystack.l_mark[0].v.opts.rtable;
			if ((h = yystack.l_mark[-1].v.addr->a) == NULL &&
			    (host_dns(yystack.l_mark[-1].v.addr->name, &h) == -1 || !h)) {
				yyerror("could not resolve \"%s\"", yystack.l_mark[-1].v.addr->name);
				free(yystack.l_mark[-1].v.addr->name);
				free(yystack.l_mark[-1].v.addr);
				YYERROR;
			}

			for (; h != NULL; h = next) {
				next = h->next;
				la = calloc(1, sizeof(struct listen_addr));
				if (la == NULL)
					fatal("listen on calloc");
				la->fd = -1;
				la->rtable = yystack.l_mark[0].v.opts.rtable;
				memcpy(&la->sa, &h->ss,
				    sizeof(struct sockaddr_storage));
				TAILQ_INSERT_TAIL(&conf->listen_addrs, la,
				    entry);
				free(h);
			}
			free(yystack.l_mark[-1].v.addr->name);
			free(yystack.l_mark[-1].v.addr);
		}
break;
case 6:
#line 133 "./parse.y"
	{
			struct ntp_peer		*p;
			struct ntp_addr		*h, *next;

			h = yystack.l_mark[-1].v.addr->a;
			do {
				if (h != NULL) {
					next = h->next;
					if (h->ss.ss_family != AF_INET &&
					    h->ss.ss_family != AF_INET6) {
						yyerror("IPv4 or IPv6 address "
						    "or hostname expected");
						free(h);
						free(yystack.l_mark[-1].v.addr->name);
						free(yystack.l_mark[-1].v.addr);
						YYERROR;
					}
					h->next = NULL;
				} else
					next = NULL;

				p = new_peer();
				p->weight = yystack.l_mark[0].v.opts.weight;
				p->rtable = yystack.l_mark[0].v.opts.rtable;
				p->addr = h;
				p->addr_head.a = h;
				p->addr_head.pool = 1;
				p->addr_head.name = strdup(yystack.l_mark[-1].v.addr->name);
				if (p->addr_head.name == NULL)
					fatal(NULL);
				if (p->addr != NULL)
					p->state = STATE_DNS_DONE;
				if (!(p->rtable > 0 && p->addr &&
				    p->addr->ss.ss_family != AF_INET))
					TAILQ_INSERT_TAIL(&conf->ntp_peers,
					    p, entry);
				h = next;
			} while (h != NULL);

			free(yystack.l_mark[-1].v.addr->name);
			free(yystack.l_mark[-1].v.addr);
		}
break;
case 7:
#line 175 "./parse.y"
	{
			struct ntp_peer		*p;
			struct ntp_addr		*h, *next;

			p = new_peer();
			for (h = yystack.l_mark[-1].v.addr->a; h != NULL; h = next) {
				next = h->next;
				if (h->ss.ss_family != AF_INET &&
				    h->ss.ss_family != AF_INET6) {
					yyerror("IPv4 or IPv6 address "
					    "or hostname expected");
					free(h);
					free(p);
					free(yystack.l_mark[-1].v.addr->name);
					free(yystack.l_mark[-1].v.addr);
					YYERROR;
				}
				h->next = p->addr;
				p->addr = h;
			}

			p->weight = yystack.l_mark[0].v.opts.weight;
			p->rtable = yystack.l_mark[0].v.opts.rtable;
			p->addr_head.a = p->addr;
			p->addr_head.pool = 0;
			p->addr_head.name = strdup(yystack.l_mark[-1].v.addr->name);
			if (p->addr_head.name == NULL)
				fatal(NULL);
			if (p->addr != NULL)
				p->state = STATE_DNS_DONE;
			if (!(p->rtable > 0 && p->addr &&
			    p->addr->ss.ss_family != AF_INET))
				TAILQ_INSERT_TAIL(&conf->ntp_peers, p, entry);
			free(yystack.l_mark[-1].v.addr->name);
			free(yystack.l_mark[-1].v.addr);
		}
break;
case 8:
#line 211 "./parse.y"
	{
			struct ntp_conf_sensor	*s;

			s = new_sensor(yystack.l_mark[-1].v.string);
			s->weight = yystack.l_mark[0].v.opts.weight;
			s->correction = yystack.l_mark[0].v.opts.correction;
			s->refstr = yystack.l_mark[0].v.opts.refstr;
			free(yystack.l_mark[-1].v.string);
			TAILQ_INSERT_TAIL(&conf->ntp_conf_sensors, s, entry);
		}
break;
case 9:
#line 223 "./parse.y"
	{
			if ((yyval.v.addr = calloc(1, sizeof(struct ntp_addr_wrap))) ==
			    NULL)
				fatal(NULL);
			if (host(yystack.l_mark[0].v.string, &yyval.v.addr->a) == -1) {
				yyerror("could not parse address spec \"%s\"",
				    yystack.l_mark[0].v.string);
				free(yystack.l_mark[0].v.string);
				free(yyval.v.addr);
				YYERROR;
			}
			yyval.v.addr->name = yystack.l_mark[0].v.string;
		}
break;
case 10:
#line 238 "./parse.y"
	{ opts_default(); }
break;
case 11:
#line 240 "./parse.y"
	{ yyval.v.opts = opts; }
break;
case 12:
#line 241 "./parse.y"
	{ opts_default(); yyval.v.opts = opts; }
break;
case 16:
#line 249 "./parse.y"
	{ opts_default(); }
break;
case 17:
#line 251 "./parse.y"
	{ yyval.v.opts = opts; }
break;
case 18:
#line 252 "./parse.y"
	{ opts_default(); yyval.v.opts = opts; }
break;
case 23:
#line 261 "./parse.y"
	{ opts_default(); }
break;
case 24:
#line 263 "./parse.y"
	{ yyval.v.opts = opts; }
break;
case 25:
#line 264 "./parse.y"
	{ opts_default(); yyval.v.opts = opts; }
break;
case 31:
#line 274 "./parse.y"
	{
			if (yystack.l_mark[0].v.number < -127000000 || yystack.l_mark[0].v.number > 127000000) {
				yyerror("correction must be between "
				    "-127000000 and 127000000 microseconds");
				YYERROR;
			}
			opts.correction = yystack.l_mark[0].v.number;
		}
break;
case 32:
#line 284 "./parse.y"
	{
			size_t l = strlen(yystack.l_mark[0].v.string);

			if (l < 1 || l > 4) {
				yyerror("refid must be 1 to 4 characters");
				free(yystack.l_mark[0].v.string);
				YYERROR;
			}
			opts.refstr = yystack.l_mark[0].v.string;
		}
break;
case 33:
#line 296 "./parse.y"
	{
			if (yystack.l_mark[0].v.number < 1 || yystack.l_mark[0].v.number > 10) {
				yyerror("weight must be between 1 and 10");
				YYERROR;
			}
			opts.weight = yystack.l_mark[0].v.number;
		}
break;
case 34:
#line 303 "./parse.y"
	{
			/* if ($2 < 0 || $2 > RT_TABLEID_MAX) { */
			/* 	yyerror("rtable must be between 1 and RT_TABLEID_MAX"); */
			/* 	YYERROR; */
			/* } */
			opts.rtable = yystack.l_mark[0].v.number;
		}
break;
#line 1088 "y.tab.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            if ((yychar = YYLEX) < 0) yychar = 0;
#if YYDEBUG
            if (yydebug)
            {
                yys = 0;
                if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
                if (!yys) yys = "illegal-symbol";
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == 0) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (short) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    yyerror("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
