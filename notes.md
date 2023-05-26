/*
    foo://example.com:8042/over/there?name=ferret#nose absolute reference
    \_/   \______________/\_________/ \_________/ \__/
    |           |            |            |        |
scheme     authority       path        query   fragment
    |   _____________________|__
    / \ /                        \
    urn:example:animal:ferret:nose //relative reference -> isRelative = true?
*/


# URI Examples

Here are some examples of Uniform Resource Identifiers (URIs):

1. **URI with authority and path of "/foo/bar" (absolute):**

http://example.com/foo/bar
path is ["", "foo", "bar"]


2. **URI with authority only and no path:**

http://example.com
path is [""]

3. **URI with authority and path of "/" (absolute):**

http://example.com/


4. **URI with authority of "example.comfoo" and path of "/bar":** (not allowed by syntax)

http://example.comfoo/bar


Parse the path

"" -> []
"/" -> [""]
"/foo" -> ["", "foo"]
"foo/" -> ["foo", ""]