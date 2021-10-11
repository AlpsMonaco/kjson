enum JSON_TYPE
{
	TYPE_NULL,
	TYPE_FALSE,
	TYPE_TRUE,
	TYPE_NUMBER,
	TYPE_STRING,
	TYPE_ARRAY,
	TYPE_OBJECT,
};

enum JSON_PARSE_STATUS
{
	STATUS_OK,
	STATUS_EMPTY_VALUE,
	STATUS_INVALID_VALUE,
	STATUS_ROOT_NOT_SINGULAR,
};

struct JsonContext
{
	const char *json;
};

void ParseWhiteSpace(JsonContext *context)
{
	const char *p = context->json;
	while (*p == ' ' || *p == '\t' || *p == '\r' || *p == '\n')
		p++;

	context->json = p;
}

#define ParseKeyword(context, keyword)\
